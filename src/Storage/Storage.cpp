//
// Created by Lenovo on 2021/6/3.
//


#include "Storage.h"

map<string,int> Storage::MaterialsList;

//获取本地食材列表
void Storage::GetMaterialsList()
{
    int n,num;
    string str;
    ifstream data;
    data.open("..\\lib\\Storage.txt");
    data >> n;                  //食材种类
    for(int i=1; i<=n; i++)
    {
        data >> str >> num;     //读入名称、数量
        MaterialsList.insert({str,num});
    }
    data.close();               //关输入流
}
//保存食材列表到本地
void Storage::SaveMaterialsList()
{
    ofstream data;
    data.open("..\\lib\\Storage.txt");
    data << MaterialsList.size() << '\n';               //食材种类
    for(const auto& x : MaterialsList)
        data << x.first << ' ' << x.second << '\n';     //写入名称、数量
    data.close();                                       //关输出流
}
//添加一种食材
bool Storage::AddMaterial(const string& name, int num)
{
    if(MaterialsList.count(name))
        MaterialsList[name] += num;
    else
        MaterialsList[name] = num;
    SaveMaterialsList();
    return true;
}
//添加多种食材
bool Storage::AddMaterial(const map<string, int>& Materials)
{
    for(const auto& x:Materials)
    {
        if(MaterialsList.count(x.first))
            MaterialsList[x.first] += x.second;
        else
            MaterialsList[x.first] = x.second;
    }
    SaveMaterialsList();
    return true;
}
//消耗一种食材
bool Storage::TakeMaterial(const string& name, int num)
{
    if(MaterialsList.count(name)&&MaterialsList[name]>=num)
    {
        if(MaterialsList[name]==num)
            MaterialsList.erase(name);
        else
            MaterialsList[name] -= num;
        SaveMaterialsList();
        return true;
    }
    return false;
}
//消耗多种食材
bool Storage::TakeMaterial(const map<string, int>& Materials)
{   //保证所有食材均充足
    for(const auto& x:Materials)
        if(!MaterialsList.count(x.first)||MaterialsList[x.first]<x.second)
            return false;
    //消耗食材
    for(const auto& x:Materials)
    {
        if(x.second==MaterialsList[x.first])
            MaterialsList.erase(x.first);
        else
            MaterialsList[x.first] -= x.second;
    }
    Storage::SaveMaterialsList();
    return true;
}
//获取某个食材的数量
int Storage::GetMaterialsNum(const string& name)
{
    if(MaterialsList.count(name))
        return MaterialsList[name];
    return 0;
}
