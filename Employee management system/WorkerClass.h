# pragma once
# include<iostream>
using namespace std;

class Worker //����Ա��������
{ 
public:
    virtual void ShowInfo() = 0; // ���麯������Ϊ��cpp�ļ��в���Դ˺�������ʵ�֣�������Ҫ���麯����
    virtual string GetPosition() = 0; // ��ȡְλ

    int m_ID;
    string m_name;
    int m_PID;

};

// ������ͨԱ��
class Employee :public Worker

{
public:
    Employee(int id, string name, int pid); // ���캯��
    void ShowInfo();
    string GetPosition();
};

//����������
class Manager :public Worker
{
public:
    Manager(int id, string name, int pid);
    void ShowInfo();
    string GetPosition();
};

//�����ϰ���
class Boss :public Worker
{
public:
    Boss(int id, string name, int pid);
    void ShowInfo();
    string GetPosition();
};