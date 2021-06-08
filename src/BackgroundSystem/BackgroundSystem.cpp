//
// Created by Lenovo on 2021/6/8.
//

#include "BackgroundSystem.h"

void BackgroundSystem::init()
{
    Dishes::GetDishList();
    Storage::GetMaterialsList();
    StaffManager::GetStaffState();
    StaffManager::GetStaffList();
}

bool BackgroundSystem::SignIn(int StaffId)
{
    try
    {
        StaffManager::StaffSignIn(StaffId);
        return true;
    }
    catch (...)
    {
        return false;
    }
}

bool BackgroundSystem::SignOut(int StaffId)
{
    try
    {
        StaffManager::StaffSignOut(StaffId);
        return true;
    }
    catch (...)
    {
        return false;
    }
}

bool BackgroundSystem::AddMaterialsToStorage(string name, int num)
{
    try
    {
        Storage::AddMaterial(name,num);
        return true;
    }
    catch (...)
    {
        return false;
    }
}

bool BackgroundSystem::AddMaterialsToStorage(map<string, int> materials)
{
    try
    {
        Storage::AddMaterial(materials);
        return true;
    }
    catch (...)
    {
        return false;
    }
}

bool BackgroundSystem::AddDishType(DishInfo dish)
{
    try
    {
        Dishes::AddDishType(dish);
        return true;
    }
    catch (...)
    {
        return false;
    }
}

bool BackgroundSystem::AddDishType(int id, string name, int price, string description, map<string, int> materialsList)
{
    try
    {
        Dishes::AddDishType(id,name,price,description,materialsList);
        return true;
    }
    catch (...)
    {
        return false;
    }
}

bool BackgroundSystem::RemoveDishType(int dishID)
{
    try
    {
        Dishes::RemoveDishType(dishID);
        return true;
    }
    catch (...)
    {
        return false;
    }
}