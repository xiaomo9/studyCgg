# pragma once
# include<iostream>
using namespace std;

class Worker //声明员工抽象类
{ 
public:
    virtual void ShowInfo() = 0; // 纯虚函数，因为在cpp文件中不会对此函数进行实现，所以需要纯虚函数。
    virtual string GetPosition() = 0; // 获取职位

    int m_ID;
    string m_name;
    int m_PID;

};

// 声明普通员工
class Employee :public Worker

{
public:
    Employee(int id, string name, int pid); // 构造函数
    void ShowInfo();
    string GetPosition();
};

//声明经理类
class Manager :public Worker
{
public:
    Manager(int id, string name, int pid);
    void ShowInfo();
    string GetPosition();
};

//声明老板类
class Boss :public Worker
{
public:
    Boss(int id, string name, int pid);
    void ShowInfo();
    string GetPosition();
};