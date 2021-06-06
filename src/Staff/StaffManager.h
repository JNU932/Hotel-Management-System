//
// Created by legion on 2021/6/6 0006.
//

#ifndef HOTEL_MANAGEMENT_SYSTEM_STAFFMANAGER_H
#define HOTEL_MANAGEMENT_SYSTEM_STAFFMANAGER_H

#include "Staff.h"
#include "map"
#include "iostream"
#include "fstream"

class StaffManager
{
private:
    //员工列表
    static map<int,Staff> StaffList;

public:
    //从本地读取员工列表
    static void GetStaffList();
    //保存员工列表到本地
    static void SaveStaffList();
    //获取员工类
    static Staff GetStaff(int id);
};


#endif //HOTEL_MANAGEMENT_SYSTEM_STAFFMANAGER_H
