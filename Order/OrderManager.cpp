#include "OrderManager.h"

bool OrderManager::OnDishFinished(int orderID, int dishID)
{
    if(OrderList.count(orderID))
    {
        return OrderList.at(orderID).FinishDish(dishID);
    }
    return false;
}

bool OrderManager::ChangeDishNums(int orderID, int dishID, int num)
{
    if(OrderList.count(orderID))
    {
        return OrderList.at(orderID).ChangeDishNums(dishID, num);
    }
    return false;
}