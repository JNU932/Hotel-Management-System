//
// Created by leg on 2021/5/27.
//

#include "Order.h"
#include "../Dish/Dishes.h"

Order::Order(int id, int pri, int cre, map<int, pair<int, int>> &list)
{
    OrderID = id;
    Price = pri;
    Creator = cre;
    DishesList = list;
}

int Order::GetOrderID() const
{
    return OrderID;
}

int Order::GetPrice() const
{
    return Price;
}

int Order::GetCreator() const
{
    return Creator;
}

bool Order::GetOrderState() const
{
    return OrderState;
}

bool Order::OrderCheck()
{
    for (auto iter = DishesList.begin(); iter != DishesList.end(); iter++)
    {
        if (iter->second.second != iter->second.second)
            return false;
    }
    return true;
}

bool Order::FinishDish(int dishID)
{ //菜品不存在
    if (!DishesList.count(dishID))
        return false;
    //超量完成
    if (DishesList[dishID].second + 1 > DishesList[dishID].first)
        return false;
    DishesList[dishID].second++;
    OrderState = OrderCheck();
    return true;
}

bool Order::ChangeDishNums(int dishID, int num)
{ //菜品不存在
    if (!DishesList.count(dishID))
        return false;
    //取消的菜品已上菜
    if (DishesList[dishID].first + num < DishesList[dishID].second)
        return false;
    DishesList[dishID].first += num;
    Price += num * Dishes::GetDishPrice(dishID);
    OrderState = OrderCheck();
    return true;
}