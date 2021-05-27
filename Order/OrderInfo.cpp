//
// Created by leg on 2021/5/27.
//

#include "OrderInfo.h"
#include "../Dish/Dishes.h"

OrderInfo::OrderInfo(int id, int pri, int cre, map<int, pair<int, int>> &list)
{
    OrderID = id;
    Price = pri;
    Creator = cre;
    DishesList = list;
}

int OrderInfo::GetOrderID() const
{
    return OrderID;
}

int OrderInfo::GetPrice() const
{
    return Price;
}

int OrderInfo::GetCreator() const
{
    return Creator;
}

bool OrderInfo::GetOrderState() const
{
    return OrderState;
}

bool OrderInfo::OrderCheck()
{
    for(auto iter = DishesList.begin(); iter!=DishesList.end(); iter++)
    {
        if(iter->second.second!=iter->second.second)
            return false;
    }
    return true;
}

bool OrderInfo::ChangeDishNums(int dishID, int num)
{   //菜品不存在
    if(!DishesList.count(dishID))
        return false;
    //取消的菜品已上菜
    if(DishesList[dishID].first+num<DishesList[dishID].second)
        return false;
    DishesList[dishID].first += num;
    Price += num*Dishes::GetDishPrice(dishID);
    OrderState = OrderCheck();
    return true;
}

bool OrderInfo::FinishDish(int dishID)
{   //菜品不存在
    if(!DishesList.count(dishID))
        return false;
    //超量完成
    if(DishesList[dishID].second+1>DishesList[dishID].first)
        return false;
    DishesList[dishID].second++;
    OrderState = OrderCheck();
    return true;
}
