//
// Created by Lenovo on 2021/6/8.
//

#ifndef HOTEL_MANAGEMENT_SYSTEM_BACKGROUNDSYSTEM_H
#define HOTEL_MANAGEMENT_SYSTEM_BACKGROUNDSYSTEM_H

#include "../Storage/Storage.h"
#include "../Dish/Dishes.h"
#include "../Staff/StaffManager.h"
#include "../Order/OrderManager.h"

class BackgroundSystem {
public:
    //系统初始化
    static void init();
    //员工签到
    static bool SignIn(int StaffId);
    //员工签退
    static bool SignOut(int StaffId);
    //添加一种食材到库存
    static bool AddMaterialsToStorage(string name, int num);
    //添加多种食材到库存
    static bool AddMaterialsToStorage(map<string, int> materials);
    //添加一种菜式
    static bool AddDishType(DishInfo dish);
    //添加一种菜式
    static bool AddDishType(int id, string name, int price, string description, map<string, int> materialsList);
    //移除一种菜式
    static bool RemoveDishType(int dishID);

};


#endif //HOTEL_MANAGEMENT_SYSTEM_BACKGROUNDSYSTEM_H
