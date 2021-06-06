//
// Created by legion on 2021/6/6 0006.
//

#include "StaffManager.h"

map<int,Staff> StaffManager::StaffList;


void StaffManager::SaveStaffList()
{
    try
    {
        ofstream data;
        data.open("..\\Data\\StaffList.txt");
        data << StaffList.size();
        for(auto x:StaffList)
        {
            data << x.second.GetID() << ' ' << x.second.GetName() << ' '
                 << x.second.GetLevel() << ' ' << x.second.GetPerformance() << '\n';
        }
        data.close();
    }
    catch (...)
    {
        cout << "Save Fail" << '\n';
    }
    
}

void StaffManager::GetStaffList()
{
    try
    {
        ifstream data;
        data.open("..\\Data\\StaffList.txt");
        int n,id,level,performance;
        string  name;
        data >> n;
        while (n--)
        {
            data >> id >> name >> level >> performance;
            StaffList.insert({id,Staff(id,name,level,performance)});
        }
        data.close();
    }
    catch (...)
    {
        cout << "Save Fail" << '\n';
    }
}

Staff StaffManager::GetStaff(int id)
{
    try 
    {
        if (!StaffList.count(id))
            throw "Wrong id\n";
        return StaffList.at(id);
    }
    catch (const char*a)
    {
        cout << a;
    }
}