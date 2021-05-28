//
// Created by leg on 2021/5/28.
//

#ifndef HOTEL_MANAGEMENT_SYSTEM_MENU_H
#define HOTEL_MANAGEMENT_SYSTEM_MENU_H

#include "../Dish/Dishes.h"
#include "../Order/OrderManager.h"

class Menu {
public:
    //获取菜单
    map<int,DishInfo> GeiDishesList();
    //传递订单给订单管理系统
    bool SendOrder(map<int, int> dishes, int creatorID, int tableID);


};


#endif //HOTEL_MANAGEMENT_SYSTEM_MENU_H
