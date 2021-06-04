//
// Created by legion on 2021/3/12 0012.
//

#ifndef HOTEL_MANAGEMENT_SYSTEM_DISHES_H
#define HOTEL_MANAGEMENT_SYSTEM_DISHES_H

#include "DishInfo.h"
#include <vector>

using namespace std;

class Dishes {
private:
    static map<int,DishInfo> DishesList;
public:
    //检查菜品的可用情况
    static bool CheckDishState(int dishID);
    //添加菜品
    static bool AddDishType(int id, string name, int price, string description, map<string, int> materialsList);
    //移除菜品
    static bool RemoveDishType(int dishID);
    //获取菜品价格
    static int GetDishPrice(int dishID);
    //获取菜品原材料
    static map<string,int> GetMaterialsList(int dishID);
    //获取菜品表单
    static map<int,DishInfo> GetDishesList();
};


#endif //HOTEL_MANAGEMENT_SYSTEM_DISHES_H
