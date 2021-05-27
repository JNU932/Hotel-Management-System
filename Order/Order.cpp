//
// Created by leg on 2021/5/27.
//

#include "Order.h"

OrderInfo Order::GenerateOrderInfo()
{

}

bool Order::OnDishFinished(int orderID, int dishID)
{
    if(OrderList.count(orderID))
    {
        OrderList.at(orderID).FinishDish(dishID);
        return true;
    }
    return false;
}

int Order::GetOrderState(int orderID)
{
    if(OrderList.count(orderID))
        return OrderList.at(orderID).GetOrderState();
    return -1;
}
