//* 职工类
#pragma once
#include<iostream>
#include"worker.hpp"
using namespace std;
class Employee:public Worker
{
    public:
    Employee(int id,string name,int p_id);
    
    void showInfor();

    string showPostname();
};