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
        data << StaffList.size() <<endl;
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
        cout << "Read Fail" << '\n';
    }
}

Staff StaffManager::GetStaff(int id)
{
    try 
    {
        if (!StaffList.count(id))
            throw "Wrong id";
        return StaffList.at(id);
    }
    catch (const char*a)
    {
        throw a;
    }
}

void StaffManager::Promote(int id, int num)
{
    try 
    {
        if (!StaffList.count(id))
            throw "Wrong id";
        StaffList.at(id).Promote(num);
    }
    catch (const char* a)
    {
        throw a;
    }
}

void StaffManager::ChangePerformance(int id, int num)
{
    try
    {
        if (!StaffList.count(id))
            throw "Wrong id";
        StaffList.at(id).ChangePerformance(num);
    }
    catch (const char* a)
    {
        throw a;
    }
}

void StaffManager::AddStaff(int id, string name, int level, int performance)
{
    try 
    {
        StaffList.insert({id,Staff(id,name,level,performance)});
        SaveStaffList();
    }
    catch (const char*a)
    {
        throw a;
    }
}

void StaffManager::DeleteStaff(int id)
{
    try 
    {
        if (!StaffList.count(id))
            throw "Wrong id";
        StaffList.erase(id);
        SaveStaffList();
    }
    catch (const char* a)
    {
        throw a;
    }
}

string StaffManager::GetStaffName(int id)
{
    try
    {
        if (!StaffList.count(id))
            throw "Wrong id";
        return StaffList.at(id).GetName();
    }
    catch (const char*a)
    {
        throw a;
    }
}

int StaffManager::GetStaffLevel(int id)
{
    try 
    {
        if (!StaffList.count(id))
            throw "Wrong id";
        return StaffList.at(id).GetLevel();
    }
    catch (const char*a)
    {
        throw a;
    }
}

int StaffManager::GetStaffPerformance(int id)
{
    try
    {
        if (!StaffList.count(id))
            throw "Wrong id";
        return StaffList.at(id).GetPerformance();
    }
    catch (const char*a)
    {
        throw a;
    }
}