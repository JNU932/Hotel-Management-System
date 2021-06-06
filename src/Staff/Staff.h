//
// Created by Lenovo on 2021/6/6.
//

#ifndef HOTEL_MANAGEMENT_SYSTEM_STAFF_H
#define HOTEL_MANAGEMENT_SYSTEM_STAFF_H

#include "string"
#include "iostream"

using namespace std;

class Staff {
private:
    //员工编号
    int StaffID;
    //员工姓名
    string StaffName;
    //员工的等级、绩效
    int StaffLevel, StaffDonate;

public:
    //构造函数
    Staff(int id, string name, int level, int donate);

    //获取ID
    int GetID() const;
    //获取姓名
    string GetName();
    //获取等级
    int GetLevel() const;
    //获取绩效
    int GetDonate() const;
    //升降职
    void Promote(int num);
    //增减绩效
    void ChangeDonate(int num);

};


#endif //HOTEL_MANAGEMENT_SYSTEM_STAFF_H
