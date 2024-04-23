//* 经理类
#include<iostream>
#include"worker.hpp"
using namespace std;
class Manager:public Worker
{
    public:
    Manager(int id,string name,int p_id);
    
    void showInfor();

    string showPostname();
};