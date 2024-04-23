#include<iostream>
#include"WorkManager.hpp"
using namespace std;
int main(){
    WorkerManager wm;
    wm.ShowMenu();
    int choice=0;
    cout<<"请输入你的选择:";
    cin>>choice; //*接受用户选项
    switch (choice)
    {
        case 0: //*退出员工系统
         wm.exitSystem();
            break;
        case 1: //*增加员工信息
         wm.Add_Emp();
            break;
        case 2://* 显示员工信息
         wm.Show_Emp();
            break;
        case 3://* 删除员工
         wm.Del_Emp();
            break;
        case 4://* 修改员工
         wm.Mod_Emp();
            break;
        case 5://* 查找员工
         wm.Find_Emp();
            break;
        case 6://* 排序员工
         wm.Sort_Emp();
            break;
        case 7://* 清空文件
         
            break;
    }
    system("pause");
    return 0;
}