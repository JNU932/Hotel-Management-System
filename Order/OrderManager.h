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
    int cnt = 0;
    map<int, Order> OrderList;

public:
    //某项菜品完成
    bool OnDishFinished(int orderID, int dishID);
    //改变订单菜品
    bool ChangeDishNums(int orderID, int dishID, int num);
};

#endif