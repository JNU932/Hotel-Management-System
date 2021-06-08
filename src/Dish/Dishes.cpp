//
// Created by legion on 2021/3/12 0012.
//

#include "Dishes.h"

map<int,DishInfo> Dishes::DishesList;

void Dishes::SaveDishesList()
{
    try
    {
        ofstream data;
        data.open("..\\Data\\DishList.txt");
        data << DishesList.size() << '\n';               //食材种类
        for(const auto& x : DishesList)
        {   //写入id、名称、价格
            data << x.first << ' '<< x.second.GetPrice() << '\n';
            //写入名称
            data << x.second.GetName() << '\n';
            //写入描述
            data << x.second.GetDescription() << '\n';
            //写入食材种类数
            data << x.second.GetMaterialsList().size() << '\n';
            //每行食材的名称、数量
            for(const auto& y :x.second.GetMaterialsList())
                data << y.first << '\n' << y.second << '\n';
        }
        data.close();                                       //关输出流
    }
    catch (...)
    {
        throw "Save Fail";
    }
}

void Dishes::GetDishList()
{
    try
    {
        int n,m,id,price,num;
        string name, description, materialname;
        ifstream data;
        data.open("..\\Data\\DishList.txt");
        if (!data)
        {
            throw "Dish File Not Found";
        }
        data >> n;                  //菜式种类
        while (n--)
        {
            //读入id、名称、价格
            data >> id >> price;
            getline(data,name);
            getline(data,name);
            getline(data,description);
            data >> m;
            map<string, int> mp;
            while (m--)
            {
                getline(data,materialname);
                getline(data,materialname);
                data >> num;
                mp.insert({materialname,num});
            }
            DishesList.insert({id,DishInfo(id,name,mp,price,description)});
        }
        data.close();               //关输入流
    }
    catch (const char*a)
    {
        throw a;
    }
    catch (...)
    {
        throw "Read Fail";
    }
}

void Dishes::AddDishType(int dishID, string name, int price, string description, map<string, int> materialsList)
{
    try
    {
        if(DishesList.count(dishID))
            throw "DishId had you le";
        DishesList.insert(make_pair(dishID,DishInfo(dishID,std::move(name),std::move(materialsList),price,std::move(description))));
        SaveDishesList();
    }
    catch (const char*a)
    {
        throw a;
    }
    catch (...)
    {
        throw "Add Fail";
    }
}

void Dishes::AddDishType(const DishInfo& dish)
{
    try
    {
        if(DishesList.count(dish.GetDishID()))
            throw "DishId you le";
        DishesList.insert({dish.GetDishID(),dish});
        SaveDishesList();
    }
    catch (const char*a)
    {
        throw a;
    }
    catch (...)
    {
        throw "Add Fail";
    }
}

void Dishes::RemoveDishType(int dishID)
{
    try
    {
        if(!DishesList.count(dishID))
            throw "Wrong DishID";
        DishesList.erase(dishID);
        SaveDishesList();
    }
    catch (const char *a)
    {
        throw a;
    }
    catch(...)
    {
        throw "Remove Fail";
    }
}

int Dishes::GetDishPrice(int dishID)
{
    try
    {
        if(!DishesList.count(dishID))
            throw "Wrong DishID";
        return DishesList.at(dishID).GetPrice();
    }
    catch (const char*a)
    {
        throw a;
    }
    catch(...)
    {
        throw "Get Fail";
    }
}
map<string, int> Dishes::GetMaterialsList(int dishID)
{
    try
    {
        if(!DishesList.count(dishID))
            throw "Wrong DishID";
        return DishesList.at(dishID).GetMaterialsList();
    }
    catch (const char*a)
    {
        throw a;
    }
    catch(...)
    {
        throw "Get Fail";
    }

}
