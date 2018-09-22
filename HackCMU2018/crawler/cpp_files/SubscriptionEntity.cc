#include <string>
#include <iostream>
#include <time.h>

#include "SubscriptionEntity.h"

using namespace std;

//mamafs::SubscriptionEntity::SubscriptionEntity()
//{
//    
//}

mamafs::SubscriptionEntity::SubscriptionEntity(string sym_name)
{
    setSymbolName(sym_name);
}

mamafs::SubscriptionEntity::~SubscriptionEntity()
{
    // should do deallocation of the mamasub here?
    
    cout << "Destroyed " << symbolName <<   endl;
}

string 
mamafs::SubscriptionEntity::getSymbolName()
{
    return symbolName;
}

void 
mamafs::SubscriptionEntity::setSymbolName(string sym_name){
    symbolName = sym_name;
    
}

string 
mamafs::SubscriptionEntity::getFilePath()
{
    return "/" + symbolName;
}

string 
mamafs::SubscriptionEntity::getMessage()
{
    return message;
}

void 
mamafs::SubscriptionEntity::setMessage(string msg)
{
    message = msg;
}

void 
mamafs::SubscriptionEntity::setUpdateTimeToNow()
{
    time (&lastUpdateTime);
}

time_t 
mamafs::SubscriptionEntity::getUpdateTime()
{
    return lastUpdateTime;
}
