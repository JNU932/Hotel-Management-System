//
// Created by leg on 2021/5/28.
//

#include "Menu.h"

map<int,DishInfo> Menu::GeiDishesList()
{
    return Dishes::GetDishesList();
}

bool Menu::SendOrder(map<int, int> dishes, int creatorID, int tableID)
{
    int price = 0;
    for(auto iter = dishes.begin(); iter!=dishes.end(); iter++)
        price += Dishes::GetDishPrice(iter->first)*iter->second;
    return OrderManager::CreateOrder(dishes,creatorID,tableID,price);
}
