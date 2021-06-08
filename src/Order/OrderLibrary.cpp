#include "OrderLibrary.h"
#include <iostream>
#include "stdio.h"

bool OrderLibrary::initialized = false;
int OrderLibrary::order_cnt = 0;

int OrderLibrary::GetNextID()
{
    if(!initialized)
    {
        InitLib();
    }
    return order_cnt;
}

void OrderLibrary::InitLib()
{


}

bool OrderLibrary::AddOrder(Order order)
{
    return true;
}