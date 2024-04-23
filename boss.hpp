//* 老板类
#pragma once
#include<iostream>
#include"worker.hpp"
using namespace std;
class Boss:public Worker
{
    public:
    Boss(int a,string s,int b);

    void showInfor();

    string showPostname();
};