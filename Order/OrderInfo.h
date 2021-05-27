//
// Created by leg on 2021/5/27.
//

#ifndef HOTEL_MANAGEMENT_SYSTEM_ORDERINFO_H
#define HOTEL_MANAGEMENT_SYSTEM_ORDERINFO_H
#include "string"
#include "map"

using namespace std;

class OrderInfo {
private:
    //订单编号
    int OrderID;
    //总价
    int Price;
    //创建者
    int Creator;
    //订单状态
    bool OrderState;
    //菜品列表, <菜品号,<菜品数量,完成数量>>
    map<int,pair<int,int>> DishesList;
    bool OrderCheck();

public:
    OrderInfo(int id, int pri, int cre, map<int,pair<int,int>>& list);
    //获取订单ID
    int GetOrderID() const;
    //获取订单总价
    int GetPrice() const;
    //获取订单创建者
    int GetCreator() const;
    //修改预定菜品数量
    bool GetOrderState() const;
    bool ChangeDishNums(int dishID, int num);
    //菜品已完成
    bool FinishDish(int dishID);
};


#endif //HOTEL_MANAGEMENT_SYSTEM_ORDERINFO_H
