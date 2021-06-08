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
    //Ա������״̬
    static map<int,int> StaffState;

public:
    //�ӱ��ض�ȡԱ���б�
    static void GetStaffList();
    //����Ա���б�����
    static void SaveStaffList();
    //�ӱ��ض�ȡԱ��״̬
    static void GetStaffState();
    //����Ա��״̬������
    static void SaveStaffState();
    //��ȡԱ����
    static Staff GetStaff(int id);
    //����ְλ
    static void Promote(int id, int num);
    //������Ч
    static void ChangePerformance(int id, int num);
    //���Ա��
    static void AddStaff(int id, string name, int level, int performance=0);
    //ɾ��Ա��
    static void DeleteStaff(int id);
    //��ȡĳ��Ա��������
    static string  GetStaffName(int id);
    //��ȡĳ��Ա����ְλ
    static int GetStaffLevel(int id);
    //��ȡĳ��Ա���ļ�Ч
    static int GetStaffPerformance(int id);
    //Ա��ǩ��
    static void StaffSignIn(int id);
    //Ա��ǩ��
    static void StaffSignOut(int id);
    
};


#endif //HOTEL_MANAGEMENT_SYSTEM_STAFFMANAGER_H
