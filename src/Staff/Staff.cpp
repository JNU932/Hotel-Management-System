//
// Created by Lenovo on 2021/6/6.
//

#include "Staff.h"


Staff::Staff(int id, string name, int level, int performance)
{
    StaffID = id;
    StaffName = std::move(name);
    StaffLevel = level;
    StaffPerformance = performance;
}

int Staff::GetID() const
{
    return StaffID;
}

string Staff::GetName()
{
    return StaffName;
}

int Staff::GetLevel() const
{
    return StaffLevel;
}

int Staff::GetPerformance() const
{
    return StaffPerformance;
}

void Staff::Promote(int num)
{
    try
    {
        if(StaffLevel+num>0)
            StaffLevel+=num;
        else
            throw "Try again";
    }
    catch (const char* a)
    {
        cout << a << endl;
    }
}
void Staff::ChangeDonate(int num)
{
    try
    {
        if(StaffPerformance+num>0)
            StaffPerformance+=num;
        else
            throw "Try again";
    }
    catch (const char* a)
    {
        cout << a << endl;
    }
}
