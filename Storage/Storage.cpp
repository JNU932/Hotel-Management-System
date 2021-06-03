//
// Created by Lenovo on 2021/6/3.
//

#include "Storage.h"

void Storage::GetFoodList()
{
    int n,num;
    string name;
    freopen("\\Data\\Storage\\FoodList.txt","r",stdin);
    while (n--)
    {
        cin >> name >> num;
        FoodStorage.insert({name,num});
    }
}

bool Storage::AddMaterial(string name, int num)
{
    if(FoodStorage.count(name))
        FoodStorage[name] += num;
    else
        FoodStorage[name] = num;
    return true;
}

bool Storage::TakeMaterial(string name, int num)
{
    if(FoodStorage.count(name)&&FoodStorage[name]>=num)
    {
        FoodStorage[name] -= num;
        return true;
    }
    return false;
}

int Storage::GetFoodNum(string name)
{
    if(FoodStorage.count(name))
        return FoodStorage[name];
    return 0;
}
