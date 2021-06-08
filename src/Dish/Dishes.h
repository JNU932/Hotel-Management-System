//
// Created by legion on 2021/3/12 0012.
//

#ifndef HOTEL_MANAGEMENT_SYSTEM_DISHES_H
#define HOTEL_MANAGEMENT_SYSTEM_DISHES_H

#include "DishInfo.h"
#include <vector>
#include "fstream"
#include "iostream"

using namespace std;

class Dishes {
private:
    static map<int,DishInfo> DishesList;
public:
    //保存菜式到本地
    static void SaveDishesList();
    //从本地读取菜式
    static void GetDishList();
    //添加菜品
    static void AddDishType(int id, string name, int price, string description, map<string, int> materialsList);
    //添加菜品
    static void AddDishType(const DishInfo& dish);
    //移除菜品
    static void RemoveDishType(int dishID);
    //获取菜品价格
    static int GetDishPrice(int dishID);
    //获取菜品原材料
    static map<string,int> GetMaterialsList(int dishID);
};


#endif //HOTEL_MANAGEMENT_SYSTEM_DISHES_H
