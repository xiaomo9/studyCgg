# include"WorkerClass.h"

// ʵ����ְͨ���ຯ��
Employee::Employee(int id, string name, int pid)
{
    this->m_ID = id;
    this->m_name = name;
    this->m_PID = pid;

}
void Employee::ShowInfo()
{
    cout << "Ա��ID��" << m_ID << "\n"
    << "Ա��������" << m_name << "\n"
    << "��λ:" << GetPosition() << "\n"
    << "��λ��ţ�" << m_PID << "\n" << endl;
}
string Employee::GetPosition()
{
    return "��ְͨ��";
}


// ʵ�־����ຯ��
Manager::Manager(int id, string name, int pid)
{
    this->m_ID = id;
    this->m_name = name;
    this->m_PID = pid;

}
void Manager::ShowInfo()
{
    cout << "����ID��" << m_ID << "\n"
    << "����������" << m_name << "\n"
    << "��λ:" << GetPosition() << "\n"
    << "��λ��ţ�" << m_PID << "\n" << endl;
}
string Manager::GetPosition()
{
    return "�����ܹ�";
}


// ʵ���ϰ��ຯ��
Boss::Boss(int id, string name, int pid)
{
    this->m_ID = id;
    this->m_name = name;
    this->m_PID = pid;

}
void Boss::ShowInfo()
{
    cout << "�ϰ�ID��" << m_ID << "\n"
    << "�ϰ�������" << m_name << "\n"
    << "��λ:" << GetPosition() << "\n"
    << "��λ��ţ�" << m_PID << "\n" << endl;
}
string Boss::GetPosition()
{
    return "�ܲ�CEO";
}