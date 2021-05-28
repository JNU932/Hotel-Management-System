//
// Created by right on 2021/5/27.
//

#ifndef HOTEL_MANAGEMENT_SYSTEM_ORDERMANAGER_H
#define HOTEL_MANAGEMENT_SYSTEM_ORDERMANAGER_H

#include "Order.h"
#include <map>
using namespace std;
class OrderManager
{
private:
    static map<int, Order> OrderList;

public:
    //改变订单菜品
    static bool ChangeDishNums(int orderID, int dishID, int num);
    //创建新的订单。创建后就会开始订单处理流程。
    //返回值为创建好的订单的订单编号
    static int CreateOrder(map<int,int> &dishesList, int creatorID, int tableID, int price);
    //当一个菜品在厨房被烹饪好后，此方法应被调用。
    static void OnDishCooked(int orderID, int dishID);
    //当一个菜品被服务员呈递给顾客后，此方法应被调用。
    static bool OnDishDelivered(int orderID, int dishID);

private:
    //结束订单
    static void FinishOrder(Order order);
};

#endif