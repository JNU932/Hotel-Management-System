//
// Created by legion on 2021/3/11 0011.
//

#ifndef HOTEL_MANAGEMENT_SYSTEM_DISH_H
#define HOTEL_MANAGEMENT_SYSTEM_DISH_H

#include <string>
#include <map>

using namespace std;

//用于在添加新菜式时传递菜品的信息
class Dish {
public:
    //菜品的名称
    string Name;
    //菜品的原材料清单
    map<string, int> MaterialsList;
    //菜品的单价
    int Price;
    //菜品的描述
    string Description;

public:
    Dish(string name, map<string, int> materials, int price, string description);
};

#endif //HOTEL_MANAGEMENT_SYSTEM_DISH_H
