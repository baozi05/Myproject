#include"WorkManager.hpp"
#include<algorithm>
bool cmp1(Worker *a,Worker *b) //* ID排序的判断(升序)
{
    return a->id<b->id;
}
bool cmp2(Worker *a,Worker *b)//* 姓名排序的判断
{
    return a->name<b->name;
}
WorkerManager::WorkerManager(){
    //* 打开文件
    ifstream ifs;
    ifs.open(File,ios::in); //*读取文件
    if(ifs.fail()){
        //* 1.文件不存在
        cout<<"文件不存在！请重试！"<<endl;
        //* 初始化
        w_num=0;
        w_Array=NULL;
        isempty=1; //* 文件为空
        ifs.close();
        system("pause");
        exit(0);
    }
        //* 2.文件存在，但文件为空
    char ch;
    ifs>>ch; //* 创建 char 型读取 ifs 文件中的第一个字符
    if(ifs.eof())//* 如果第一个字符就是终止符----文件为空
    {
        cout<<"空文件！请重试！"<<endl;
        w_Array=NULL;
        w_num=0;
        isempty=true;
        ifs.close();
        system("pause");
        exit(0);
    }
    //* 3.文件存在，可以正常记录数据
    w_num=this->get_num();
    //cout<<"共有职工"<<w_num<<"名"<<endl;
    //* 开辟数组
    w_Array=new Worker*[w_num];
    init_Emp();//* 初始化，将文件中数据存入数组

}
void WorkerManager::ShowMenu(){
    
    cout << "**************************" << endl;
	cout << "**欢迎使用员工管理系统！**" << endl;
	cout << "******0.退出管理系统******" << endl;
	cout << "******1.增加员工信息******" << endl;
	cout << "******2.显示员工信息******" << endl;
	cout << "******3.删除离职员工******" << endl;
	cout << "******4.修改员工信息******" << endl;
	cout << "******5.查找员工信息******" << endl;
	cout << "******6.选择方式排序******" << endl;
	cout << "**************************" << endl;
	cout << endl;
}

void WorkerManager::exitSystem(){
    cout<<"欢迎下次使用！"<<endl;
    system("pause");
    exit(0); //* 退出程序
}
void WorkerManager::Add_Emp(){
    cout<<"请输入需要添加的人数：";
    int n;cin>>n;
    if(n>0){
        //* 需要扩容数组，加开容量
        int newsize=n+w_num;
        Worker **newspace=new Worker*[newsize] ;
        //* 接下来操作参考顺序表中的扩容操作，即开辟新空间，拷贝原数据至新空间，在原数据后增加新数据
        if(w_Array!=NULL) //*如果原数据非空
        {
            for(int i=0;i<w_num;i++)
            //* 拷贝原数据
            {
                newspace[i]=w_Array[i];
            }
            for(int i=w_num;i<newsize;i++){
                //* 增添新数据
                int new_id;
                string new_name;
                int post;  //*员工数据输入
                cout<<"请输入你需要添加的第"<<i-w_num+1<<"位职工的信息"<<endl;
                cout<<"ID:";
                cin>>new_id;
                // while (IsExist(new_id)!=-1)
                // {
                //     cout<<"添加失败，该ID已经被占用！请重新输入：";
                //     cin>>new_id;
                // }//! 添加如果id重复需要重新输入的操作
                cout<<"姓名:";
                cin.ignore();
                cin>>new_name;
                cout<<"请选择该职工的岗位:"<<endl;
                cout << "1.普通员工" << endl;
			    cout << "2.经理" << endl;
			    cout << "3.老板" << endl;
                cin>>post;
                Worker *newWorker=NULL; //*初始化职工岗位
                switch (post)
                {
                case 1: newWorker=new Employee(new_id,new_name,1);
                    break;
                case 2: newWorker=new Manager(new_id,new_name,2);
                    break;
                case 3: newWorker=new Boss(new_id,new_name,3);
                    break;
                }
                newspace[i]=newWorker;//* 把新创建的职工添加到数组中
            }
            delete [] w_Array; //* 释放原有数据的空间
            w_Array=newspace; //* 将原数组指向更新至新数组
            w_num=newsize; //* 扩容容量
            isempty=0; //* 文件不为空
            cout<<"成功添加职工"<<n<<"名！"<<endl;
            this->save(); //* 保存数据到文件
        }
    }    
    else{
        cout<<"输入有误！"<<endl;
    }    
    system("pause");
    system("cls"); 
    //* 可按任意键请屏，返回上一级目录
}
void WorkerManager::save(){
    ofstream ofs;
    ofs.open(File,ios::out); //* 写文件
    //* 读写每一个人的数据
    for(int i=0;i<w_num;i++){
        ofs<<w_Array[i]->id<<' '
        <<w_Array[i]->name<<' '
        <<w_Array[i]->postid<<endl;
    }
    ofs.close();
}
int WorkerManager::get_num(){
    ifstream ifs;//*读写文件
    ifs.open(File,ios::in);
    int num=0;
    int id;
    string name;
    int postid;
    while(ifs>>id&&ifs>>name&&ifs>>postid)//* 如果能读写到一个成员的所有数据
        num++;
    return num;
}
void WorkerManager::init_Emp() //*初始化员工
{
    //* 即读取文件之后将职工信息存储进数组中
    ifstream ifs;
    ifs.open(File,ios::in);
    int index=0;
    int id;
    string name;
    int postid;
    while(ifs>>id&&ifs>>name&&ifs>>postid){
     Worker *worker;
        if(postid==1) 
        worker=new Employee(id,name,postid);
        if(postid==2) 
        worker=new Manager(id,name,postid);
        if(postid==3) 
        worker=new Boss(id,name,postid);
        w_Array[index]=worker;
        index++;
    }
    ifs.close();
}
void WorkerManager::Show_Emp() //* 展示员工信息(ALL)
{
    for(int i=0;i<w_num;i++){
        w_Array[i]->showInfor();
    }
    system("pause");
    system("cls");
}
int WorkerManager::IsExist(int id){
    for(int i=0;i<w_num;i++){
        if(w_Array[i]->id==id)
        return i;
    }
    return -1;
}
void WorkerManager::Find_Emp()//* 查找员工
{
    cout<<"请输入查找方式："<<endl;
    cout<<"1.按照姓名"<<endl;
    cout<<"2.按照职工编号"<<endl;
    int choice;
    flag:
    cin>>choice;
    if(choice==2){
        int id;
        cout<<"请输入需要查找的职工编号:";
        cin>>id;
        if(IsExist(id)!=-1){
            cout<<"查找成功！该员工的信息为："<<endl;
            w_Array[IsExist(id)]->showInfor();
        }
        else cout<<"查找失败，查无此人！"<<endl;
    }
    else if(choice==1){
        string name;
        cout<<"请输入员工姓名：";
        cin>>name;
        bool Flag=false; //* 查找成功的标志
        for(int i=0;i<w_num;i++){
            if(w_Array[i]->name==name)
            {
                cout<<"查找成功！该员工的信息为："<<endl;
                w_Array[i]->showInfor();
                Flag=true;
                break;
            }
        }
        if(!Flag){
            cout<<"查找失败！查无此人！"<<endl;
        }
    }
    else{
        cout<<"输入有误！请重新输入:"<<endl;
        goto flag;
    }   
}
void WorkerManager::Mod_Emp(){
    cout<<"请输入你想要修改的员工ID:"<<endl;
    int id,index;
    cin>>id;
    index=IsExist(id);
    if(id!=-1)
    {
    cout<<"修改员工："<<endl;
    w_Array[index]->showInfor();
    cout<<"请输入修改信息："<<endl;
    int newid;
    string newname;
    int newpost;
    cout<<endl<<"ID:";
    cin>>newid;
    cout<<endl<<"名字：";
    cin>>newname;
    cout<<endl<<"选择职位：";
    cout<<"1.职工"<<endl
        <<"2.经理"<<endl
        <<"3.老板"<<endl;
    cin>>newpost;
    // delete w_Array[index];
    // Worker *worker;
    // switch (newpost)
    // {
    // case 1:worker=new Employee(newid,newname,newpost);
    //     break;
    // case 2:worker=new Manager(newid,newname,newpost);
    //     break;
    // case 3:worker=new Boss(newid,newname,newpost);
    //     break;
    // default:
    //     break;
    // }
    // w_Array[index]=worker;
    w_Array[index]->id=newid;
    w_Array[index]->name=newname;
    w_Array[index]->postid=newpost;
    //? 两种方法，其一是删除该空间后重建，其二是直接修改该空间内的数据
    cout<<"修改成功！新职工信息："<<endl;
    w_Array[index]->showInfor();
    save();
    }
    else{
        cout<<"查无此人！修改失败！"<<endl;
    }
    system("pause");
    system("cls");
}
void WorkerManager::Sort_Emp(){
    cout<<"请选择排序方式："<<endl;
    cout<<"1.按照姓名(首字母)排序"<<endl;
    cout<<"2.按照职工ID排序"<<endl;
    int choice;
    flag:
    cin>>choice;
    if(choice==1){
        sort(w_Array,w_Array+w_num,cmp2);
        cout<<"按照姓名排序："<<endl;
        for(int i=0;i<w_num;i++)
        w_Array[i]->showInfor();
    }
    else if(choice==2){
        sort(w_Array,w_Array+w_num,cmp1);
        for(int i=0;i<w_num;i++)
        w_Array[i]->showInfor();
    }
    else{
         cout<<"输入有误！请重新输入："<<endl;
         goto flag;
        }

    
}
void WorkerManager::Del_Emp(){
    cout<<"请输入你想删除的员工ID:"<<endl;
    int id;
    flag:
    cin>>id;
    int index=IsExist(id);
    if(index==-1){
        cout<<"查无此人！请重新输入：";
        goto flag;
    }
    else {
        cout<<"删除员工："<<endl;
        w_Array[index]->showInfor();
        cout<<"确定删除？"<<endl;
        int choice;
        cout<<"1---是    2---否"<<endl;
        cin>>choice;
        if(choice==1)
        //? 删除后类似于顺序表，需要前移数据
       {
        for(int i=index;i<w_num-1;i++){
            w_Array[i]=w_Array[i+1];
        }
        w_num--;
        save();
        cout<<"删除成功！"<<endl;
    }
    }
    system("pause");
    system("cls");
}
WorkerManager::~WorkerManager(){
    if(w_Array!=NULL) //* 开辟到堆区的数据需要手动析构
    {
        delete [] w_Array;
        w_Array=NULL;
    }
}
