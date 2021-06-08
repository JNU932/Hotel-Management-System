//
// Created by legion on 2021/3/12 0012.
//

#include "DishInfo.h"

#include <utility>

DishInfo::DishInfo(int dishID, string name, map<std::string, int> materials, int price, string description) {
    DishID = dishID;
    Name = std::move(name);
    MaterialsList = std::move(materials);
    Price = price;
    Description = std::move(description);
}

int DishInfo::GetDishID() const {return DishID;}
string DishInfo::GetName() const {return Name;}
map<std::string, int> DishInfo::GetMaterialsList() const {return MaterialsList;}
int DishInfo::GetPrice() const {return Price;}
string DishInfo::GetDescription() const {return Description;}