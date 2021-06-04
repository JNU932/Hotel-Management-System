//
// Created by leg on 2021/5/27.
//

#include "Kitchen.h"

bool Kitchen::AddTask(int orderID, int dishID)
{
    map<string,int> MaterialsList = Dishes::GetMaterialsList(dishID);
    for(auto x:MaterialsList)
        if(Storage::GetMaterialsNum(x.first)<x.second)
            return false;
    for(auto x:MaterialsList)
        Storage::TakeMaterial(x.first,x.second);
    return true;
}

void Kitchen::FinishTask(int orderID, int dishID)
{
    OrderManager::OnDishCooked(orderID,dishID);
}