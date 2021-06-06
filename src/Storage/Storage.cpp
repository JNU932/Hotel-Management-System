//
// Created by Lenovo on 2021/6/3.
//


#include "Storage.h"

void Storage::GetMaterialsList()
{
    int n,num;
    string str;
    ifstream data;
    data.open("..\\lib\\Storage.txt");
    data >> n;
    for(int i=1; i<=n; i++)
    {
        data >> str >> num;
        MaterialsList.insert({str,num});
    }
    data.close();
}

void Storage::SaveMaterialsList()
{
    ofstream data;
    data.open("..\\lib\\Storage.txt");
    data << MaterialsList.size() << '\n';
    for(auto x : MaterialsList)
        data << x.first << ' ' << x.second << '\n';
    data.close();
}

bool Storage::AddMaterial(const string& name, int num)
{
    if(MaterialsList.count(name))
        MaterialsList[name] += num;
    else
        MaterialsList[name] = num;
    SaveMaterialsList();
    return true;
}

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

int Storage::GetMaterialsNum(string &name)
{
    if(MaterialsList.count(name))
        return MaterialsList[name];
    return 0;
}
