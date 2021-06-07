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
    //升降职位
    static void Promote(int id, int num);
    //增减绩效
    static void ChangePerformance(int id, int num);
    //添加员工
    static void AddStaff(int id, string name, int level, int performance=0);
    //删除员工
    static void DeleteStaff(int id);
    //获取某个员工的姓名
    static string  GetStaffName(int id);
    //获取某个员工的职位
    static int GetStaffLevel(int id);
    //获取某个员工的绩效
    static int GetStaffPerformance(int id);
    
};


#endif //HOTEL_MANAGEMENT_SYSTEM_STAFFMANAGER_H
