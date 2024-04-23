#include"employee.hpp"
Employee::Employee(int a,string s,int b){
    id=a;
    name=s;
    postid=b;
}
void Employee::showInfor(){
    cout<<"员工ID:"<<id<<endl
    <<"员工姓名:"<<name<<endl
    <<"员工岗位:"<<this->showPostname()<<endl
    <<"职责:完成经理下发的任务"<<endl;
}
string Employee::showPostname(){
    return ("员工");
}