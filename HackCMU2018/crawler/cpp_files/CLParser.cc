#include <iostream>

#include "CLParser.h"
#include "MamaRunner.h"

#include <cstring>

using namespace std;
using namespace mamafs;

mamafs::CLParser::CLParser(int argc, char **argv) {
    
    MamaRunner *mr = MamaRunner::getInstance();
    
    int i = 1; // args count
    
    //cout << argc << " Arguments passed" << endl;
    
    //default values for arguments
    
    foreground  =   false;
    debug       =   false;
    middleware  =   NULL;
    mountpoint  =   NULL;
    tport       =   NULL;
    source      =   NULL;
        
    while ( i < argc ) {
        
        if (compare(argv[i], "-M")){
            mountpoint = argv[++i];
//            cout << "-M passed as : " <<  mountpoint << endl;
        }
        else if (compare(argv[i], "-tport") || compare(argv[i], "-T")){
            tport = argv[++i];
//            cout << "-T or -tport passed as : " <<  tport << endl;
            mr->tport_str = tport; 
        }
        else if (compare(argv[i], "-S")){
            
            source = argv[++i];
//            cout << "-S passed as " <<  source << endl;
            mr->source_str = source;
        }
        else if (compare(argv[i], "-m")){
            middleware = argv[++i];
//            cout << "-m passed as " <<  middleware << endl;
            mr->middlware_str = middleware;
        }
        else if ( (compare(argv[i], "-F") || (compare(argv[i], "--foreground")) ) ){
//            cout << "-F passed " << endl;
            foreground = true;
        }
        else if ( compare(argv[i], "--debug")  ){
//            cout << "--debug passed " << endl;
            debug = true;
        }
        else if ( compare(argv[i], "-?" ) || compare(argv[i], "-h") || compare(argv[i], "-help" ) ) {
            cout << "HELP requested" << endl;
            cout << "TODO: print usage!!!!" << endl;
            exit(0) ;
        }
        
        ++i;
    }//wend
    
    // todo : exit if mountpoint/tport/source are missing then display help
    
    cout << endl;
}

mamafs::CLParser::~CLParser() {
    
}

bool 
mamafs::CLParser::compare(char * s1, char * s2) {
    if (strcmp(s1, s2) != 0)
        return false;
    else
        return true;
}

/*
 * arg_ar - array to be modified
 */
int 
mamafs::CLParser::getFuseArgs(char ** arg_ar) {
    
    int num = 0;
    
    arg_ar[num] = new char[12];
    arg_ar[num] = strdup("exename");
    
    if (mountpoint != NULL)
    {
        arg_ar[++num] = new char[strlen(mountpoint)];
        arg_ar[num] = mountpoint;
    }
    
    if (foreground)
    {
        arg_ar[++num] = new char[3];
        arg_ar[num] = strdup("-f");
    }
    
    if (debug)
    {
        arg_ar[++num] = new char[3];
        arg_ar[num] = strdup("-d");
    }
    // more ?
    return ++num;
    
}

void 
mamafs::CLParser::printFuseArgs() {
    char * new_args[10];
    int x;
    
    int c = getFuseArgs(new_args);
    
    for (x = 0; x < c; x++) {
        cout << "Fuse Arg #" << x << " = "<<  new_args[x] << endl;
    }
}
