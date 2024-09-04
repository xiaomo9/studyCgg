# include "workerManager.h"

// 员工信息初始化
WorkerManager::WorkerManager()//构造函数
{
    ifstream isf;
    isf.open(FILENAME,ios::in); //读文件

    // 如果文件不存在
    if (!isf.is_open()) 
    {   
        cout << "职工信息文件不存在" << endl;
        this->m_NumEmploy = 0; 
        this->WorkerArray = NULL;
        this->m_fileIsEmpty = true;
        isf.close();
        return;
    }

    // 如果文件为空
    char ch;
    isf >> ch; // 读取一个字节的数据
    if (isf.eof()) // 判断现在是否已经指向文件尾部
    {
        cout << "文件为空！" << endl;
        this->m_NumEmploy = 0; 
        this->WorkerArray = NULL;
        this->m_fileIsEmpty = true;
        isf.close();
        return;
    }

    // 如果文件不为空
    int num = GetNumEmploy();
    this->m_NumEmploy = num;
    this->m_fileIsEmpty = false;
    // 开辟新的数组空间
    this->WorkerArray = new Worker *[this->m_NumEmploy];
    this->initEmployArray(); // 调用初始化函数，初始化数组
}               

// 页面展示
void WorkerManager::ShowMenu()
{
    cout << "****************************" << endl;
    cout << "****欢迎使用职工管理系统***" << endl;
    cout << "***** 0、退出管理程序 *****" << endl;
    cout << "***** 1、添加职工信息 *****" << endl;
    cout << "***** 2、显示职工信息 *****" << endl;
    cout << "***** 3、删除离职职工 *****" << endl;
    cout << "***** 4、修改职工信息 *****" << endl;
    cout << "***** 5、查找职工信息 *****" << endl;
    cout << "***** 6、按照编号排序 *****" << endl;
    cout << "***** 7、清空所有文档 *****" << endl;
    cout << "****************************" << endl;

}

// 退出系统功能
void WorkerManager::ExitSystem()
{
    cout << "感谢使用本系统" << endl;
    system("pause");
    exit(0); //退出程序
}

// 保存职工信息到指定文件夹
void WorkerManager::save()
{
    ofstream ofs;
    ofs.open(FILENAME,ios::out);

    for(int i = 0; i < this->m_NumEmploy; i++)
    {
        ofs << this->WorkerArray[i]->m_ID << " "
        << this->WorkerArray[i]->m_name << " "
        << this->WorkerArray[i]->m_PID << " " << endl;
    }
    ofs.close();
}

// 获取当前职工人数
int WorkerManager ::GetNumEmploy()
{
    ifstream ifs;
    ifs.open(FILENAME,ios::in);
    int ID;
    string name;
    int DID;
    int num = 0; // 计数
    while (ifs >> ID && ifs >> name && ifs >> DID)
    {
        num ++;
    }
    return num;
}

// 初始化职工列表
void WorkerManager ::initEmployArray()
{
    ifstream ifs;
    ifs.open(FILENAME,ios::in);

    int id;
    string name;
    int did;
    int dix = 0;
    while(ifs >> id && ifs >> name && ifs >> did)
    {
        Worker *worker = NULL;
        if(did==1)
        {
            worker = new Employee(id,name,did);
        }
        else if(did == 2)
        {
            worker = new Manager(id, name, did);
        }
        else
        {
            worker = new Boss(id, name, did);
        }
        this->WorkerArray[dix] = worker;
        dix ++;
    }
}

// 添加职工系统功能
void WorkerManager::AddEmploy()
{
    int addnum;//要添加的人数
    cout << "请输入要添加的人数:" << endl;
    cin >> addnum;
    int id;// 编号
    string name; //姓名
    int pid; //职位编号

    //添加员工
    if (addnum > 0)
    {
        int new_workernum = this->m_NumEmploy + addnum; //新的员工数量
        Worker ** NewSpace = new Worker *[new_workernum]; //新的员工列表存储
        // 将原有员工信息转移到新的空间中
        if(this->WorkerArray != NULL)
        {
            for(int i = 0; i < this->m_NumEmploy; i++)
            {
                NewSpace[i] = this->WorkerArray[i];
            }
        }

        for(int i = 0; i<addnum; i++)
        {
            cout << "输入第" << i+1 << "名员工的编号:" << endl;
            cin >> id;
            cout << "输入第" << i+1 << "名员工的姓名:" << endl;
            cin >> name;
            cout << "输入第" << i+1 << "名员工的职位:" << endl;
            cout << "1、普通职工" << endl;
            cout << "2、经理" << endl;
            cout << "3、老板" << endl;
            cin >> pid;

            Worker * wk = NULL;
            switch (pid)
            {
            case 1:
                wk = new Employee(id,name,pid);
                break;
            case 2:
                wk = new Manager(id,name,pid);
                break;
            case 3:
                wk = new Boss(id,name,pid);
                break;
            default:
                break;
            }

            NewSpace[this->m_NumEmploy + i] = wk;
        }
        // 释放原有空间
        delete [] this->WorkerArray;
        // 更改员工列表指向
        this->WorkerArray = NewSpace;
        // 更新员工数量
        this->m_NumEmploy = new_workernum;
        cout << "成功添加" << addnum << "名职工" << endl;
        // 更新文件是否为空标签
        this->m_fileIsEmpty = false;
        save(); // 将员工信息保存到文件中。
    }
    else
    {
        cout << "输入有误请检查" << endl;
    }
    
    system("pause");
    system("cls");
}

// 展示职工信息功能
void WorkerManager::Show_Employ()
{
    if (this->m_fileIsEmpty)
    {
        cout << "当前职工信息为空！" << endl;
    }
    else{
        for(int i = 0; i < this->m_NumEmploy; i++)
        {
            this->WorkerArray[i]->ShowInfo();// 展示职工信息函数调用
        }
    }
    system("pause");
    system("cls");
}

// 判断要查找的职工是否存在
int WorkerManager::Employ_IsExit(int id)
{
    int idx = -1;
    for(int i = 0; i < this->m_NumEmploy; i++)
    {
        if(this->WorkerArray[i]->m_ID == id)
        {
            idx = i;
            break;
        }
    }
    return idx;
}

// 删除指定职工
void WorkerManager::Del_Employ()
{
    if(this->m_fileIsEmpty)
    {
        cout << "职工信息文件为空" << endl;
    }
    else
    {
        int del_id;  // 获取要删除职工的ID
        cout << "请输入要删除的职工ID:" << endl;
        cin >> del_id;
        int idex; // 得到要删除员工的索引
        idex = this->Employ_IsExit(del_id);
        if(idex==-1)
        {
            cout << "该员工不存在" << endl;
        }
        else
        {
            for(int i = idex; i < this->m_NumEmploy-1; i++)
            {
                Worker *Temp = NULL;
                this->WorkerArray[i] = this->WorkerArray[i+1];
            }
            this->m_NumEmploy--;
            this->save();
            cout << "删除成功" << endl;
        }
    }
    system("pause");
    system("cls");
}

//修改职工信息
void WorkerManager::Mod_Employ()
{
    if(this->m_fileIsEmpty) // 职工信息是否为空
    {
        cout << "职工信息为空" << endl;
    }
    else{
        int mod_id;
        cout << "输入要修改职工编号：" << endl;
        cin >> mod_id;
        int idex = this->Employ_IsExit(mod_id);
        if(idex == -1) // 员工是否存在
        {
            cout << "该员工不存在" << endl;
        }
        else{
            Worker *wk = NULL;
            int id;
            string name;
            int pid;
            cout << "====输入修改后的信息：====" << endl;
            cout << "输入职工编号：" << endl;
            cin >> id;
            cout << "输入职工姓名：" << endl;
            cin >> name;
            cout << "输入职工职位" << endl;
            cout << "1、普通职工" << endl;
            cout << "2、经理" << endl;
            cout << "3、老板" << endl;
            cin >> pid;
            switch (pid)
            {
            case 1:
                wk = new Employee(id,name,pid);
                break;
            case 2:
                wk = new Manager(id,name,pid);
                break;
            case 3:
                wk = new Boss(id,name,pid);
                break;
            default:
                break;
            }
            this->WorkerArray[idex] = wk;
        }
        this->save();
    }
    system("pause");
    system("cls");
}

// 查找职工信息
void WorkerManager::Find_Employ()
{
    if (this->m_fileIsEmpty)
    {
        cout << "职工信息为空！" << endl;
    }
    else
    {
        int chance;
        cout << "输入查找职工的方式：" << endl;
        cout << "1、按职工编号查找" << "\n"
             << "2、按职工姓名查找" << endl;
        cin >> chance;
        if(chance == 1)
        {
            cout << "输入要查找的职工编号：" << endl;
            int find_id;
            cin >> find_id;
            int ret = this->Employ_IsExit(find_id);
            if(ret != -1)
            {
                cout << "职工编号为  " << find_id << "  的员工信息如下：" << endl;
                this->WorkerArray[ret]->ShowInfo();
            }
            else{cout << "未查到此人！" << endl;}
        }
        else if(chance == 2)
        {
            string find_name;
            cout << "请输入要查找的职工姓名：" << endl;
            cin >> find_name;
            bool flag = false; // 判断是否查到
            for(int i = 0; i < this->m_NumEmploy; i++)
            {
                if(this->WorkerArray[i]->m_name == find_name)
                {
                    flag = true;
                    cout << "姓名为  " << find_name << "  的员工信息如下：" << endl;
                    this->WorkerArray[i]->ShowInfo();
                }
            }
            if(flag == false)
            {
                cout << "未查到此人信息！" << endl;
            }
        }
        else{cout << "请输入正确查找方式！" << endl;}
    }

    system("pause");
    system("cls");
}


//  按编号排序
void WorkerManager::Sort_Employ()
{
    if (this->m_fileIsEmpty)
    {
        cout << "职工信息为空！" << endl;
        system("pause");
        system("cls");
    }
    else
    {
        cout << "请选择排序方式：" << endl;
        cout << "1、按职工编号升序" << "\n"
             << "2、按职工编号降序" << endl;
        int Select; // 用户选择的排序方式
        cin >> Select;
        for(int i = 0; i < this->m_NumEmploy - 1; i++)
        {
            int minOrmax = i; //最大最小值索引
            for(int j = i+1; j < this->m_NumEmploy; j++)
            {            
                if (Select == 1) // 升序排序
                {
                    if(this->WorkerArray[minOrmax]->m_ID > this->WorkerArray[j]->m_ID)
                    {
                        minOrmax = j;
                    }
                }
                if(Select == 2)
                {
                    if(this->WorkerArray[minOrmax]->m_ID < this->WorkerArray[j]->m_ID)
                    {
                        minOrmax = j;
                    }
                }
            }

            //把最小值或最大值提到首位
            Worker * tem = this->WorkerArray[minOrmax];
            this->WorkerArray[minOrmax] = this->WorkerArray[i];
            this->WorkerArray[i] = tem;
        }
    this->save();
    cout << "排序完成，现在的信息结构如下：" << endl;
    this->Show_Employ();
    }
}

// 清空职工信息
void WorkerManager::Cls_Employ()
{
    cout << "请输入密码进行后续操作" << endl;
    string password;
    cin >> password;
    if (password == "12345678")
    {
        cout << "确定清空所有内容吗？" << "\n"
         << "1、确定" << "\n"
         << "2、返回" << endl;
         int select;
         cin >> select;
        if(select == 1)
        {
            ofstream osf;
            osf.open(FILENAME,ios::trunc); // 删除原有文件，新建同名文件
            // 清空堆区内所有内容
            //清空每个职工信息
            delete [] this->WorkerArray;
            this->WorkerArray = NULL;
            this->m_NumEmploy = 0;
            this->m_fileIsEmpty = true;
            cout << "所有信息都已经成功清空！" << endl;
        }
    }
    else
    {
        cout << "密码错误，您无此权限！！";
    }
    system("pause");
    system("cls");
}

WorkerManager::~WorkerManager()
{   

}
