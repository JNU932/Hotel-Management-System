//
// Created by leg on 2021/5/27.
//

#ifndef HOTEL_MANAGEMENT_SYSTEM_KITCHEN_H
#define HOTEL_MANAGEMENT_SYSTEM_KITCHEN_H

#include "../Order/OrderManager.h"
#include "../Dish/Dishes.h"
#include "../Storage/Storage.h"

class Kitchen{
public:
    //添加菜品制作任务
    bool AddTask(int orderID, int dishID);
    //菜品制作完成
    void FinishTask(int orderID, int dishID);
    //orderID: 订单编号   dishID: 菜品编号
};


#endif //HOTEL_MANAGEMENT_SYSTEM_KITCHEN_H
