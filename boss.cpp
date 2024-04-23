#include"boss.hpp"
Boss::Boss(int a,string s,int b){
    this->id=a;
    this->name=s;
    this->postid=b;
}
void Boss::showInfor(){
    cout<<"员工ID:"<<id<<endl
    <<"员工姓名:"<<name<<endl
    <<"员工岗位:"<<this->showPostname()<<endl
    <<"职责:管理公司事务"<<endl;
}
string Boss::showPostname(){
    return ("CEO");
}