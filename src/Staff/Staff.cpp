//
// Created by Lenovo on 2021/6/6.
//

#include "Staff.h"

Staff::Staff(int id, string name, int level, int donate)
{
    StaffID = id;
    StaffName = name;
    StaffLevel = level;
    StaffDonate = donate;
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

int Staff::GetDonate() const
{
    return StaffDonate;
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
        if(StaffDonate+num>0)
            StaffDonate+=num;
        else
            throw "Try again";
    }
    catch (const char* a)
    {
        cout << a << endl;
    }
}
