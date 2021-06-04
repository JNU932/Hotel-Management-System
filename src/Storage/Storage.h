//
// Created by Lenovo on 2021/6/3.
//

#ifndef HOTEL_MANAGEMENT_SYSTEM_STORAGE_H
#define HOTEL_MANAGEMENT_SYSTEM_STORAGE_H

#include "string"
#include "map"
#include "iostream"
#include <fstream>

using namespace std;

class Storage {
private:
    //食材库存
    static map<string,int> MaterialsList;
public:
    //从硬盘中获取食材列表
    static void GetMaterialsList();
    //保存当前食材列表到硬盘
    static void SaveMaterialsList();
    //添加食材
    static bool AddMaterial(string name, int num);
    //消耗食材
    static bool TakeMaterial(string name, int num);
    //查询食材数量
    static int GetMaterialsNum(string name);
};


#endif //HOTEL_MANAGEMENT_SYSTEM_STORAGE_H
