//
// Created by legion on 2021/3/11 0011.
//

#include "Dish.h"

#include <utility>

Dish::Dish(string name, map<string, int> materials, int price, string description) {
    Name = std::move(name);
    MaterialsList = std::move(materials);
    Price = price;
    Description = std::move(description);
}