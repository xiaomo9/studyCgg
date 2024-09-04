# include"WorkerClass.h"

// 实现普通职工类函数
Employee::Employee(int id, string name, int pid)
{
    this->m_ID = id;
    this->m_name = name;
    this->m_PID = pid;

}
void Employee::ShowInfo()
{
    cout << "员工ID：" << m_ID << "\n"
    << "员工姓名：" << m_name << "\n"
    << "岗位:" << GetPosition() << "\n"
    << "岗位编号：" << m_PID << "\n" << endl;
}
string Employee::GetPosition()
{
    return "普通职工";
}


// 实现经理类函数
Manager::Manager(int id, string name, int pid)
{
    this->m_ID = id;
    this->m_name = name;
    this->m_PID = pid;

}
void Manager::ShowInfo()
{
    cout << "经理ID：" << m_ID << "\n"
    << "经理姓名：" << m_name << "\n"
    << "岗位:" << GetPosition() << "\n"
    << "岗位编号：" << m_PID << "\n" << endl;
}
string Manager::GetPosition()
{
    return "大内总管";
}


// 实现老板类函数
Boss::Boss(int id, string name, int pid)
{
    this->m_ID = id;
    this->m_name = name;
    this->m_PID = pid;

}
void Boss::ShowInfo()
{
    cout << "老板ID：" << m_ID << "\n"
    << "老板姓名：" << m_name << "\n"
    << "岗位:" << GetPosition() << "\n"
    << "岗位编号：" << m_PID << "\n" << endl;
}
string Boss::GetPosition()
{
    return "总裁CEO";
}