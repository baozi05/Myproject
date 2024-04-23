#include"manager.hpp"
Manager::Manager(int a,string s,int b){
    id=a;
    name=s;
    postid=b;
}
void Manager::showInfor(){
    cout<<"员工ID:"<<id<<endl
    <<"员工姓名:"<<name<<endl
    <<"员工岗位:"<<this->showPostname()<<endl
    <<"职责:完成老板下发的任务,并将任务下发给员工"<<endl;
}
string Manager::showPostname(){
    return ("经理");
}