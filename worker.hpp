#pragma once
#include<iostream>
using namespace std;
class Worker{
    public:
    //* 显示个人信息
    virtual void showInfor()=0;

    //* 获取个人岗位
    virtual string showPostname()=0;

    int id;
    string name;
    int postid; //  职工所在部门编号
};