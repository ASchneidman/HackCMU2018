#include "dialog.h"

RailsDialog::RailsDialog( QWidget *parent, const char *name, WFlags f, QString rDir, QString rConf, QString rApp )
  : QWidget(parent, name, f)
{
  /* get config; command-line arguments take precedence */
  conf = new KSimpleConfig("krailsrc");
  if (rDir.isNull()) {
    railsPath = conf->readEntry("working_dir", QDir::homeDirPath() + "/rails");
    saveDir = true;
  }
  else {
    railsPath = rDir;
    saveDir = false;
  }
  
  if (rConf.isNull()) {
    tabConf = conf->readEntry("tab_conf", QString::null);
    saveConf = true;
  }
  else {
    tabConf = rConf;
    saveConf = false;
  }

  if (rApp.isNull()) {
    appName = conf->readEntry("app_name", QString::null);
    saveApp = true;
  }
  else {
    appName = rApp;
    saveApp = false;
  }

  grid = new QGridLayout(this, 4, 3, 0, 5);
  grid->addWidget( new QLabel( "Working directory:", this ), 0, 0 );
  grid->addWidget( new QLabel( "Configuration:", this ), 1, 0 );
  grid->addWidget( new QLabel( "Application:", this ), 2, 0 );

  leRailsDir = new KLineEdit( railsPath, this );
  leRailsDir->setReadOnly(true);
  leTabConf  = new KLineEdit( tabConf, this );
  leTabConf->setReadOnly(true);
  cbRailsApp = new KComboBox( this );
  grid->addWidget( leRailsDir, 0, 1 );
  grid->addWidget( leTabConf,  1, 1 );
  grid->addWidget( cbRailsApp, 2, 1 );

  btnDir     = new KPushButton( "Change", this );
  btnConf    = new KPushButton( "Change", this );
  grid->addWidget( btnDir, 0, 2 );
  grid->addWidget( btnConf, 1, 2 );

  hbox       = new QHBox( this );
  btnGo      = new KPushButton( "Go", hbox );
  btnCancel  = new KPushButton( "Cancel", hbox );
  grid->addMultiCellWidget( hbox, 3, 3, 1, 2 );

  connect(btnGo, SIGNAL(clicked()), SLOT(go()));
  connect(btnCancel, SIGNAL(clicked()), kapp, SLOT(quit()));
  connect(btnDir, SIGNAL(clicked()), SLOT(changeDir()));
  connect(btnConf, SIGNAL(clicked()), SLOT(changeConf()));
  connect(cbRailsApp, SIGNAL(activated(int)), SLOT(appChanged(int)));

  findApplications();
}

void RailsDialog::go()
{
  int errcode, pid;
  QString error;

  appDir  = railsPath + "/" + appName;

  // fire up konsole
  QString konsoleName( "konsole-script" );
  errcode = KApplication::startServiceByDesktopName( konsoleName, QString::null, &error, &dcopService, &pid );
  konsole.setRef( dcopService, "konsole" );
  session.clear();

  if (tabConf.isNull()) {
    session.setRef( dcopService, "session-1" );
    setupSession("spec-dev", "spec");
    newSession("spec");
    newSession("dev1");
    newSession("dev2");
    newSession("dev3");
    newSession("cnsl", "", "script/console");
    newSession("log", "log", "tail -f test.log");
    newSession("db");
    newSession("srv", "", "script/server webrick");
    
    if (QFile::exists(appDir + "/vendor/rails"))
      newSession("src", "vendor/rails");
    else
      newSession("src", "/usr/lib/ruby/gems/1.8/gems");

    newSession("misc");
  }
  else {
    /* use custom configuration file */
    ConfigHandler handler( this );
    QXmlSimpleReader reader;
    QFile file( tabConf );
    QXmlInputSource source( file );
    reader.setContentHandler( &handler );
    reader.parse( source );
  }

  if (saveDir)  conf->writeEntry("working_dir", railsPath);
  if (saveConf) conf->writeEntry("tab_conf", tabConf);
  if (saveApp)  conf->writeEntry("app_name", appName);
  conf->sync();
  kapp->quit();
}

void RailsDialog::changeDir()
{
  KURL url = KDirSelectDialog::selectDirectory(railsPath, true, this, "Select Rails Directory:");
  if (url.isEmpty() || url.path() == railsPath) {
    return;
  }
  railsPath = url.path();
  leRailsDir->setText(railsPath);
  findApplications();
  saveDir = true;
  saveApp = true;
}

void RailsDialog::changeConf()
{
  QString fn = KFileDialog::getOpenFileName(QString::null, "*.xml", this, "Select tab configuration:");
  if (fn.isEmpty() || fn == tabConf) {
    return;
  }
  tabConf = fn;
  leTabConf->setText(tabConf);
  saveConf = true;
}

void RailsDialog::appChanged( int )
{
  appName = cbRailsApp->currentText();
  saveApp = true;
}

// find rails applications
void RailsDialog::findApplications()
{
  int index = -1;
  cbRailsApp->clear();
  QDir railsDir( railsPath );
  QStringList files = railsDir.entryList();
  for ( QStringList::Iterator it = files.begin(); it != files.end(); ++it ) {
    if ( *it == "." || *it == ".." )
      continue;

    QFileInfo info( railsPath + "/" + *it );
    if (info.isDir()) {
      cbRailsApp->insertItem( *it );
      if (appName == *it) {
        index = cbRailsApp->count()-1;
        /*qDebug( "found %s as %d", appName.latin1(), index );*/
      }
      /*qDebug( "%s %d", (*it).latin1(), cbRailsApp->count());*/
    }
  }

  if (index > 0)
    cbRailsApp->setCurrentItem(index);
  else
    appName = cbRailsApp->currentText();
}

void RailsDialog::setupSession( QString name, QString subpath, QString exec )
{
  session.send( "renameSession", name );
  session.send( "sendSession", "cd " + appDir + "/" + subpath );
  session.send( "sendSession", "clear" );

  if (!exec.isEmpty())
    session.send( "sendSession", exec );
}

void RailsDialog::newSession( QString name, QString subpath, QString exec )
{
  if (session.isNull()) {
    session.setRef( dcopService, "session-1" );
  }
  else {
    QString sessionName;
    DCOPReply result = konsole.call( "newSession" );
    result.get(sessionName);
    session.setRef( dcopService, sessionName.utf8() );
  }
  setupSession( name, subpath, exec );
}
