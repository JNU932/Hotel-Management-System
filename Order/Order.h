//
// Created by leg on 2021/5/27.
//

#ifndef HOTEL_MANAGEMENT_SYSTEM_ORDER_H
#define HOTEL_MANAGEMENT_SYSTEM_ORDER_H

using namespace std;

class Order
{
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
    map<int, pair<int, int>> DishesList;

    //当菜品完成后，检查订单是否已完成
    bool OrderCheck();
public:
    Order(int id, int pri, int cre, map<int, pair<int, int>> &list);

    //获取订单ID
    int GetOrderID() const;
    //获取订单总价
    int GetPrice() const;
    //获取订单创建者
    int GetCreator() const;
    //修改预定菜品数量
    bool ChangeDishNums(int dishID, int num);
    //获取订单状态
    bool GetOrderState() const;
    //完成菜品
    bool FinishDish(int dishID);
    //添加或移除菜品
    bool ChangeDishNums(int dishID, int num);
};

#endif //HOTEL_MANAGEMENT_SYSTEM_ORDER_H
