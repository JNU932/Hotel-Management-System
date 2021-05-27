//
// Created by leg on 2021/5/27.
//

#ifndef HOTEL_MANAGEMENT_SYSTEM_ORDER_H
#define HOTEL_MANAGEMENT_SYSTEM_ORDER_H

#include "OrderInfo.h"

using namespace std;

class Order {
private:
    int cnt = 0;
    map<int,OrderInfo> OrderList;
public:
    //生成订单
    OrderInfo GenerateOrderInfo();
    //某项菜品完成
    bool OnDishFinished(int orderID, int dishID);
    //获取订单状态  0:未完成  1:已完成  -1:订单不存在
    int GetOrderState(int orderID);
};


#endif //HOTEL_MANAGEMENT_SYSTEM_ORDER_H
