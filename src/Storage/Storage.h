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
    //从本地获取食材列表
    static void GetMaterialsList();
    //保存当前食材列表到本地
    static void SaveMaterialsList();
    //添加一种食材
    static bool AddMaterial(const string& name, int num);
    //添加多种食材
    static bool AddMaterial(const map<string,int>& Materials);
    //消耗一种食材
    static bool TakeMaterial(const string& name, int num);
    //消耗多种食材
    static bool TakeMaterial(const map<string,int>& Materials);
    //查询食材数量
    static int GetMaterialsNum(const string& name);
};


#endif //HOTEL_MANAGEMENT_SYSTEM_STORAGE_H
