#include<iostream>
#include<vector>
#include<map>
using namespace std;
#include<ctime>

// 员工类
class Worker
{
public:
    string m_name;
    int m_salary;

    Worker(string name, int salary)
    {
        this->m_name = name;
        this->m_salary = salary;
    }
};


// 自动创建员工函数
void createWorker(vector<Worker> &v)
{
    string namestr = "ABCDEFGHIJ";
    for(int i =0; i<10; i++)
    {
        string name = "员工";
        name += namestr[i];
        int salary = rand() % 10000 +10001;
        Worker w1(name,salary);
        v.push_back(w1);
    }
}

// 给员工加上部门
void department(vector<Worker>&v, multimap<int,Worker>&mp)
{
    for(vector<Worker>::iterator it = v.begin(); it != v.end(); it ++)
    {
        int departnum = rand() % 3 ;
        mp.insert(make_pair(departnum,*it));
    }
}

// 分部门展示员工 
void ShowbyDepart(multimap<int,Worker>&mp)
{
    //策划部
    cout<< "策划部：" << endl;
    multimap<int,Worker>::iterator it;
    it = mp.find(0); // 策划部起始迭代器（因为map容器根据编号自动排序）
    int num = mp.count(0); // 找到本部门一共多少人
    for(int idex = 0; idex < num ;idex++,it++)
    {
        cout << (*it).second.m_name << " 薪资为:" << (*it).second.m_salary << endl; 
    }

    //美术部
    cout << "------------" << endl;
    cout<< "美术部：" << endl;
    it = mp.find(1); // 美术部起始迭代器（因为map容器根据编号自动排序）
    num = mp.count(1); // 找到本部门一共多少人
    for(int idex = 0; idex < num ;idex++,it++)
    {
        cout << (*it).second.m_name << " 薪资为:" << (*it).second.m_salary << endl; 
    }

    //开发部
    cout << "----------" << endl;
    cout<< "开发部：" << endl;
    it = mp.find(2); // 开发部起始迭代器（因为map容器根据键自动排序）
    num = mp.count(2); // 找到本部门一共多少人
    for(int idex = 0; idex < num ;idex++,it++)
    {
        cout << (*it).second.m_name << " 薪资为:" << (*it).second.m_salary << endl; 
    }
}

int main()
{
    //随机数种子
    srand((unsigned int) time(NULL));
    // 创建员工数组容器
    vector<Worker> vworker;
    // 自动创建员工
    createWorker(vworker);
    // 带部门编号的员工容器
    multimap<int,Worker> mp;
    // 自动初始化部门编号
    department(vworker,mp);
    // 分部门展示员工
    ShowbyDepart(mp);
    system("pause");
}
