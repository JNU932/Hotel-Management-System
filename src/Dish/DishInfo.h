//
// Created by legion on 2021/3/12 0012.
//

#ifndef HOTEL_MANAGEMENT_SYSTEM_DISHINFO_H
#define HOTEL_MANAGEMENT_SYSTEM_DISHINFO_H

#include <string>
#include <map>

using std::string;
using std::map;

class DishInfo {
private:

    //菜品编号
    int DishID;
    //菜品名
    string Name;
    //菜品单价
    int Price;
    //描述
    string Description;
    //菜品的原材料清单
    map<string, int> MaterialsList;
public:
    DishInfo(int dishID, string name, map<std::string, int> materials, int price, string description);
    
    int GetDishID() const;
    string GetName() const;
    map<std::string, int> GetMaterialsList() const;
    int GetPrice() const;
    string GetDescription() const;
    
};


#endif //HOTEL_MANAGEMENT_SYSTEM_DISHINFO_H
