//
// Created by legion on 2021/3/12 0012.
//

#ifndef HOTEL_MANAGEMENT_SYSTEM_DISHES_H
#define HOTEL_MANAGEMENT_SYSTEM_DISHES_H

#include "DishInfo.h"
#include <vector>

using namespace std;

class Dishes {
public:
    //检查菜品的可用情况
    bool CheckDishState(int dishID);
    //添加菜品
    int AddDishType(string name, int price, string description, map<string, int> materialsList);
    //移除菜品
    bool RemoveDishType(int dishID);
    //获取菜品表单
    vector<DishInfo> GetDishesList();
};


#endif //HOTEL_MANAGEMENT_SYSTEM_DISHES_H
