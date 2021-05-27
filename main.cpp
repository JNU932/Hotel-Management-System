//
// Created by legion on 2021/3/6 0006.
//

#include <iostream>
#include "./Dish/Dishes.h"

using namespace std;

int main(){
    auto m = map<string, int>();
    m["Apple"] = 2;
    m["Salt"] = 1;
    
    Dish dish = Dish( "Apple soup", m, 12,  "a bowl of apple soup.");
    cout << dish.MaterialsList.size() << endl;
    m["123"] = 5;
    cout << dish.MaterialsList.size() << endl;
}
