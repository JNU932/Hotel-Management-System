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
    FILE *f = fopen("/Orders/LibraryInfo.csv", "r");
    if(f == 0)
    {
        f = fopen("/Orders/LibraryInfo.csv", "w+");
        char *ordercnt_str = "order_cnt";
        fprintf(f, "%s\n", ordercnt_str);
        fprintf(f, "%d\n", 0);
    }
    fscanf(f, "%s");

}