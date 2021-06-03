//
// Created by leg on 2021/5/27.
//

#include "Kitchen.h"

void Kitchen::AddTask(int orderID, int dishID)
{

}

void Kitchen::FinishTask(int orderID, int dishID)
{
    OrderManager::OnDishCooked(orderID,dishID);
}