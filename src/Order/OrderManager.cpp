#include "OrderManager.h"
#include "OrderLibrary.h"

map<int, Order> OrderManager::OrderList;

bool OrderManager::ChangeDishNums(int orderID, int dishID, int num)
{
    if(OrderList.count(orderID))
    {
        return OrderList.at(orderID).ChangeDishNums(dishID, num);
    }
    return false;
}

int OrderManager::CreateOrder(map<int,int> &dishesList, int creatorID, int tableID, int price)
{
    int id = OrderLibrary::GetNextID();
    if(id == -1)
    {
        return -1;
    }
    map<int, pair<int, int>> dish_list;

    //初始化菜品清单
    for(pair<int, int> p : dishesList)
    {
        dish_list.insert(make_pair(p.first, make_pair(p.second, 0)));
    }

    

    //创建订单
    Order order = Order(id, price, creatorID, dish_list);
    OrderList.insert(make_pair(id, order));

    return id;
}

void OrderManager::OnDishCooked(int orderID, int dishID)
{
    if(OrderList.count(orderID))
    {
        Order order = OrderList.at(orderID);
        order.FinishDish(dishID);
        if(order.GetOrderState())
        {
            //订单完成
            FinishOrder(order);
        }
    }
}

bool OrderManager::OnDishDelivered(int orderID, int dishID)
{
    if(OrderList.count(orderID))
    {
        return OrderList.at(orderID).FinishDish(dishID);
    }
    return false;
}

void OrderManager::FinishOrder(Order order)
{
    if(OrderLibrary::AddOrder(order))
    {
        OrderList.erase(order.GetOrderID());
    }
}