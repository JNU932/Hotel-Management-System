//
// Created by right on 2021/5/27.
//
#pragma
#ifndef HOTEL_MANAGEMENT_SYSTEM_ORDERLIBRARY_H
#define HOTEL_MANAGEMENT_SYSTEM_ORDERLIBRARY_H

#include "../Order/Order.h"
using namespace std;
class OrderLibrary
{
private:
    static bool initialized;
    static int order_cnt;

public:
    //获取订单信息
    static Order GetOrder(int orderID);
    //添加新的订单到订单库中
    static bool AddOrder(Order order);
    //获得下一个订单编号
    static int GetNextID();

private:
    //初始化订单库
    static void InitLib();
};

#endif