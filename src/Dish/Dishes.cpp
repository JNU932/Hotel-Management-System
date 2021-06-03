//
// Created by legion on 2021/3/12 0012.
//

#include "Dishes.h"

map<int,DishInfo> Dishes::DishesList;

bool Dishes::CheckDishState(int dishID) {
    return false;
}

bool Dishes::AddDishType(int dishID, string name, int price, string description, map<string, int> materialsList) {
    if(DishesList.count(dishID))
        return false;
    DishesList.insert(make_pair(dishID,DishInfo(dishID,true,name,materialsList,price,description)));
    return true;
}

bool Dishes::RemoveDishType(int dishID) {
    if(!DishesList.count(dishID))
        return false;
    DishesList.erase(dishID);
    return true;
}

int Dishes::GetDishPrice(int dishID)
{
    if(DishesList.count(dishID))
    {
        return DishesList.at(dishID).GetPrice();
    }
    return -1;
}

map<int,DishInfo> Dishes::GetDishesList() {
    return DishesList;
}
