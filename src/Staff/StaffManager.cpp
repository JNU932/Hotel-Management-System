//
// Created by legion on 2021/6/6 0006.
//

#include "StaffManager.h"

map<int,Staff> StaffManager::StaffList;
map<int,int> StaffManager::StaffState;


void StaffManager::SaveStaffList()
{
    try
    {
        ofstream data;
        data.open("..\\Data\\StaffList.txt");
        data << StaffList.size() <<endl;
        for(auto x:StaffList)
        {
            data << x.second.GetName() << '\n';
            data << x.second.GetID() << ' ' << x.second.GetLevel() << ' ' << x.second.GetPerformance() << '\n';
        }
        data.close();
    }
    catch (...)
    {
        throw "Save Fail";
    }
}

void StaffManager::GetStaffList()
{
    try
    {
        ifstream data;
        data.open("..\\Data\\StaffList.txt");
        if(!data)
            throw "Staff File not found";
        int n,id,level,performance;
        string  name;
        data >> n;
        while (n--)
        {
            getline(data,name);   //读入\n
            getline(data,name);   //读入name
            data >> id >> level >> performance;
            StaffList.insert({id,Staff(id,name,level,performance)});
        }
        data.close();
    }
    catch (const char* a)
    {
        throw a;
    }
    catch (...)
    {
        throw "Read Fail";
    }
}

void StaffManager::GetStaffState()
{
    try
    {
        ifstream data;
        data.open("..\\Data\\StaffState.txt");
        int n,id,state;
        data >> n;
        while (n--)
        {
            data >> id >> state;
            StaffState.insert({id,state});
        }
        data.close();
    }
    catch (...)
    {
        cout << "Read Fail" << '\n';
    }
}

void StaffManager::SaveStaffState()
{
    try
    {
        ofstream data;
        data.open("..\\Data\\StaffState.txt");
        data << StaffState.size() << endl;
        for(auto x:StaffState)
            data << x.first << ' ' << x.second << '\n';
        data.close();
    }
    catch (...)
    {
        throw "Save Fail";
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
        if(StaffList.count(id))
            throw "StaffId you le";
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

void StaffManager::StaffSignIn(int id)
{
    try
    {
        if(!StaffState.count(id))
            throw "Wrong id";
        else if(StaffState[id]==1)
            throw "Staff had sign in";
        else
            StaffState[id] = 1;
        SaveStaffState();
    }
    catch (const char* a)
    {
        throw a;
    }
    catch (...)
    {
        throw "Sign In Fail";
    }
}

void StaffManager::StaffSignOut(int id)
{
    try
    {
        if(!StaffState.count(id))
            throw "Wrong id";
        else if(StaffState[id]==0)
            throw "Staff have not signed in";
        else
            StaffState[id] = 0;
        SaveStaffState();
    }
    catch (const char* a)
    {
        throw a;
    }
    catch (...)
    {
        throw "Sign Out Fail";
    }
}