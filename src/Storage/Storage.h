//
// Created by Lenovo on 2021/6/3.
//

#ifndef HOTEL_MANAGEMENT_SYSTEM_STORAGE_H
#define HOTEL_MANAGEMENT_SYSTEM_STORAGE_H

#include "string"
#include "map"

using namespace std;

class Storage {
private:
    //食材库存
    static map<string,int> FoodStorage;
public:
    //添加食材
    static bool AddMaterial(string name, int num);
    //移除食材
    static bool TakeMaterial(string name, int num);
    //查询食材数量
    static int GetFoodNum(string name);
};


#endif //HOTEL_MANAGEMENT_SYSTEM_STORAGE_H
