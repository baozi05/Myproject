#include<iostream>
#pragma once
#include"boss.hpp"
#include"employee.hpp"
#include"manager.hpp"
#include<fstream>
#define File "Arrangement/Worker_File.txt"
using namespace std;
class WorkerManager{
    public:
    
    Worker **  w_Array; //* 储存员工的数组

    int w_num;//* 统计员工人数

    bool isempty; //*判断文件是否为空

    WorkerManager(); //*构造
    
    ~WorkerManager(); //*析构

    void ShowMenu(); //*展示菜单

    void exitSystem(); //*退出

    void Add_Emp();//* 添加员工

    //* 因为在创建员工时，有多种员工种类，若要把所有员工（不同种类）放进同一个数组，就需要将员工指针都放进同一个数组里
    //* 所以需要 Worker **的指针
    // 即 Worker *w = new Boss/Employee/Manager  ---第一个指针创建 Worker 类的动态空间，第二个指针作为数组储存
    // new Worker*[n];
    void save();//* 保存文件

    int get_num();//* 获取员工数量

    void init_Emp();//* 初始化职工

    void Find_Emp();//* 查找人员

    void Sort_Emp();//* 排序职工

    void Del_Emp();//* 删除职工

    void Show_Emp();//* 展示员工信息

    int IsExist(int id);//*用于判断职工是否存在，如果存在则返回职工所在数组中的位置，不存在返回-1

	void Mod_Emp();//*修改职工
};