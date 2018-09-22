
#include "MamaRunner.h"

#include <string>
#include <iostream>
#include <mama/mamacpp.h>
#include <iostream>
#include <sstream>

using namespace mamafs;

bool  mamafs::MamaRunner::instFlag = false;
MamaRunner * mamafs::MamaRunner::inst = NULL;
MamafsMessageCallback  * mamafs::MamaRunner::msgCbs =  new MamafsMessageCallback;

MamaRunner * mamafs::MamaRunner::getInstance()
{
    if (!instFlag)
    {
        inst = new MamaRunner();
        instFlag = true;

        return inst;
    }
    else
    {
        return inst;
    }
}

void mamafs::MamaRunner::startMama()
{
    Mama::start(mBridge);
}

void mamafs::MamaRunner::stopMama()
{
    Mama::stop(mBridge);
}

void mamafs::MamaRunner::startMamaInBackground()
{
    StartCallback * msc = new StartCallback;
    Mama::startBackground(mBridge,  msc);   
}

mamafs::MamaRunner::~MamaRunner()
{
    instFlag = false;
    delete inst;
}

void mamafs::MamaRunner::init()
{
    // todo: extract all settings to be command line params
    
    mBridge = Mama::loadBridge(middlware_str);
    Mama::open();
    mDefQueue = Mama::getDefaultEventQueue(mBridge);

    mTransport = new MamaTransport();
    std::cout << " TPORT: " <<  tport_str << std::endl;
    mTransport->create(tport_str, mBridge);
    mTransport->setOutboundThrottle(9000, MAMA_THROTTLE_INITIAL);
    
    mSource = new Wombat::MamaSource(source_str, mTransport, "WOMBAT");

    fetchDataDictionary();    
    
}
