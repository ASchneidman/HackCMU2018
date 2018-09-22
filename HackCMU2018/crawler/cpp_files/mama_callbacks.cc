/*
 * Contains implementations of Callbacks For:
 *
 * MamafsMessageCallback -> MamaSubscriptionCallback
 * DictionaryCallback    -> MamaDictionaryCallback
 * StartCallback         -> MamaStartCallback
 *
 */

/*
 * MamaSubscriptionCallback Implementation
 */
 
#include "mama_callbacks.h"
#include "MamaRunner.h"
#include "SubscriptionEntity.h"
#include "SubscriptionStore.h"

#include <mama/mamacpp.h>

#include <iostream>
#include <sstream>

using namespace mamafs;
using namespace std;

mamafs::MamafsMessageCallback::~MamafsMessageCallback ()
{
    
}

void 
mamafs::MamafsMessageCallback::onCreate (MamaSubscription* subscription)
{
    MamaRunner * mr = MamaRunner::getInstance();
    SubscriptionStore *ss = SubscriptionStore::getInstance();
    std::map<string, SubscriptionEntity*>::iterator iter;
    
    iter = ss->subs.find(subscription->getSymbol());    
    
    ostringstream msgStream;
    
    msgStream << "Subscription for " << subscription->getSymbol() 
              << " created" << endl;

    (*iter).second->setMessage(msgStream.str());
    (*iter).second->setUpdateTimeToNow();
}

void 
mamafs::MamafsMessageCallback::onError(MamaSubscription* subscription,
                                            const MamaStatus& status, 
                                            const char* symbol)
{

    MamaRunner * mr = MamaRunner::getInstance();
    SubscriptionStore *ss = SubscriptionStore::getInstance();
    std::map<string, SubscriptionEntity*>::iterator iter;

    iter = ss->subs.find(subscription->getSymbol());

    ostringstream msgStream;

    msgStream << "Subscription for " << subscription->getSymbol()
              << " - Error:  " << status.toString()  << endl;

    (*iter).second->setMessage(msgStream.str());
    (*iter).second->setUpdateTimeToNow();

    cout << msgStream.str() << endl;

}

void 
mamafs::MamafsMessageCallback::onQuality (MamaSubscription *subscription, 
                                               mamaQuality quality, 
                                               const char *symbol, 
                                               short cause, 
                                               const void *platformInfo)
{
    MamaRunner * mr = MamaRunner::getInstance();
    SubscriptionStore *ss = SubscriptionStore::getInstance();
    std::map<string, SubscriptionEntity*>::iterator iter;

    iter = ss->subs.find(subscription->getSymbol());

    ostringstream msgStream;

    msgStream << "Subscription for " << subscription->getSymbol()
              << " onQuality:   " << quality.toString()  << endl;


    (*iter).second->setMessage(msgStream.str());
    (*iter).second->setUpdateTimeToNow();

    cout << msgStream.str() << endl;


}

void 
mamafs::MamafsMessageCallback::onMsg(MamaSubscription*  subscription,
                                     MamaMsg&     msg)
{   
    char tmp[100];
    MamaRunner * mr = MamaRunner::getInstance();
    SubscriptionStore *ss = SubscriptionStore::getInstance();
    std::map<string, SubscriptionEntity*>::iterator iter;
    
    iter = ss->subs.find(subscription->getSymbol());
    
    ostringstream msgStream;
    
    msgStream <<  msg.getMsgTypeName() << " recieved for " 
              << subscription->getSymbol() << " [Seq Num: " 
	      << msg.getSeqNum() << "]" << endl;
    
    const MamaFieldDescriptor * mFieldDesc;
    MamaMsgIterator mm_iter(mr->mDictionary);
    MamaMsgField field = NULL;
    
    msg.begin(mm_iter);
    
    while (*mm_iter != NULL)
    {
        (*mm_iter).getAsString(tmp,100);
        mFieldDesc = (*mm_iter).getDescriptor();
        msgStream << mFieldDesc->getName() << ", " 
		  << (*mm_iter).getTypeName() << ", " 
                  <<  tmp << endl;
        ++mm_iter;
    }
    
    (*iter).second->setMessage(msgStream.str());
    (*iter).second->setUpdateTimeToNow();
    
   // cout << msgStream.str();
}

void 
mamafs::MamafsMessageCallback::onGap (MamaSubscription* subscription)
{
    
}

void 
mamafs::MamafsMessageCallback::onRecapRequest (MamaSubscription* subscription)
{
    
}

/*
 * END OF MamaSubscriptionCallback Implementation
 */


/*
 * Dictionary Callbacks
 */
void 
mamafs::DictionaryCallback::onTimeout()
{
    std::cout << "Dictionary Timeout called" << std::endl;
    MamaRunner * mr = mamafs::MamaRunner::getInstance();
    mr->stopMama();

}

void 
mamafs::DictionaryCallback::onError(const char * errMsg)
{
    std::cout << "Dictionary Error Called" << std::endl;
    MamaRunner * mr = mamafs::MamaRunner::getInstance();
    mr->stopMama();
}

void 
mamafs::DictionaryCallback::onComplete()
{
    std::cout << "Dictionary received" << std::endl;
    MamaRunner * mr = mamafs::MamaRunner::getInstance();
    mr->stopMama();

}

void 
mamafs::MamaRunner::fetchDataDictionary()
{

    mDictionary = new MamaDictionary;
    DictionaryCallback dictCallbacks;
    
    dSource = new Wombat::MamaSource("WOMBAT", mTransport, "WOMBAT");
   
    mDictionary->create(mDefQueue,
                        &dictCallbacks,
                        dSource,
                        3,
                        10.0);
    
     MamaRunner * mr = mamafs::MamaRunner::getInstance();
     mr->startMama();
     
}

void 
mamafs::StartCallback::onStartComplete(MamaStatus status)
{
    cout << "MamaStartCallback called with status " <<status.toString() << endl;
}

