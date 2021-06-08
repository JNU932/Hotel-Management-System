//
// Created by Lenovo on 2021/6/3.
//


#include <cstring>
#include "Storage.h"

map<string,int> Storage::MaterialsList;

//获取本地食材列表
void Storage::GetMaterialsList()
{
    try 
    {
        int n,num;
        string str;
        ifstream data;
        data.open("..\\Data\\Storage.txt");
        if (!data)
        {
            throw "Storage File Not Found";
        }
        data >> n;                  //食材种类
        for(int i=1; i<=n; i++)
        {
            getline(data,str);  //读入\n
            getline(data,str);  //读入名称
            data >> num;     //读入数量
            MaterialsList.insert({str,num});
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
//保存食材列表到本地
void Storage::SaveMaterialsList()
{
    try 
    {
        ofstream data;
        data.open("..\\Data\\Storage.txt");
        data << MaterialsList.size() << '\n';               //食材种类
        for(const auto& x : MaterialsList)
            data << x.first << '\n' << x.second << '\n';     //写入名称、数量
        data.close();                                       //关输出流
    }
    catch (...)
    {
        throw "Save Fail";
    }
}
//添加一种食材
void Storage::AddMaterial(const string& name, int num)
{
    try 
    {
        if(MaterialsList.count(name))
            MaterialsList[name] += num;
        else
            MaterialsList[name] = num;
        SaveMaterialsList();
    }
    catch (...)
    {
        throw "Add Fail";
    }
}
//添加多种食材
void Storage::AddMaterial(const map<string, int>& Materials)
{
    try
    {
        for(const auto& x:Materials)
        {
            if(MaterialsList.count(x.first))
                MaterialsList[x.first] += x.second;
            else
                MaterialsList[x.first] = x.second;
        }
        SaveMaterialsList();
    }
    catch (...)
    {
        throw "Add Fail";
    }
}
//消耗一种食材
void Storage::TakeMaterial(const string& name, int num)
{
    try
    {   //食材名称有误
        if (!MaterialsList.count(name))
            throw "Wrong Name";
        //食材数量有误
        if (MaterialsList[name]<num)
            throw "Num Too Large";
        
        if(MaterialsList[name]==num)
            MaterialsList.erase(name);
        else
            MaterialsList[name] -= num;
        SaveMaterialsList();
    }
    catch (const char*a)
    {
        throw a;
    }
}
//消耗多种食材
void Storage::TakeMaterial(const map<string, int>& Materials)
{   
    try 
    {
        //保证所有食材均充足
        for(pair<string, int> x:Materials)
        {
            if (!MaterialsList.count(x.first) || MaterialsList[x.first] < x.second)
                throw x.first;
        }
        //消耗食材
        for(const auto& x:Materials)
        {
            if(x.second==MaterialsList[x.first])
                MaterialsList.erase(x.first);
            else
                MaterialsList[x.first] -= x.second;
        }
        Storage::SaveMaterialsList();
    }
    catch (string &a)
    {
        throw a;
    }

}
//获取某个食材的数量
int Storage::GetMaterialsNum(const string& name)
{
    try
    {
        if (MaterialsList.count(name))
            return MaterialsList[name];
        else
            throw false;
    }
    catch (bool a)
    {
        throw "Wrong name";
    }
    return 0;
}