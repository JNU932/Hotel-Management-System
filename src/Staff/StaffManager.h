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
    //Ա���б�
    static map<int,Staff> StaffList;

public:
    //�ӱ��ض�ȡԱ���б�
    static void GetStaffList();
    //����Ա���б�����
    static void SaveStaffList();
    //��ȡԱ����
    static Staff GetStaff(int id);
};


#endif //HOTEL_MANAGEMENT_SYSTEM_STAFFMANAGER_H
