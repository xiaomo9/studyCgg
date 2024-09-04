#include<iostream>
#include<vector>
#include<map>
using namespace std;
#include<ctime>

// Ա����
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


// �Զ�����Ա������
void createWorker(vector<Worker> &v)
{
    string namestr = "ABCDEFGHIJ";
    for(int i =0; i<10; i++)
    {
        string name = "Ա��";
        name += namestr[i];
        int salary = rand() % 10000 +10001;
        Worker w1(name,salary);
        v.push_back(w1);
    }
}

// ��Ա�����ϲ���
void department(vector<Worker>&v, multimap<int,Worker>&mp)
{
    for(vector<Worker>::iterator it = v.begin(); it != v.end(); it ++)
    {
        int departnum = rand() % 3 ;
        mp.insert(make_pair(departnum,*it));
    }
}

// �ֲ���չʾԱ�� 
void ShowbyDepart(multimap<int,Worker>&mp)
{
    //�߻���
    cout<< "�߻�����" << endl;
    multimap<int,Worker>::iterator it;
    it = mp.find(0); // �߻�����ʼ����������Ϊmap�������ݱ���Զ�����
    int num = mp.count(0); // �ҵ�������һ��������
    for(int idex = 0; idex < num ;idex++,it++)
    {
        cout << (*it).second.m_name << " н��Ϊ:" << (*it).second.m_salary << endl; 
    }

    //������
    cout << "------------" << endl;
    cout<< "��������" << endl;
    it = mp.find(1); // ��������ʼ����������Ϊmap�������ݱ���Զ�����
    num = mp.count(1); // �ҵ�������һ��������
    for(int idex = 0; idex < num ;idex++,it++)
    {
        cout << (*it).second.m_name << " н��Ϊ:" << (*it).second.m_salary << endl; 
    }

    //������
    cout << "----------" << endl;
    cout<< "��������" << endl;
    it = mp.find(2); // ��������ʼ����������Ϊmap�������ݼ��Զ�����
    num = mp.count(2); // �ҵ�������һ��������
    for(int idex = 0; idex < num ;idex++,it++)
    {
        cout << (*it).second.m_name << " н��Ϊ:" << (*it).second.m_salary << endl; 
    }
}

int main()
{
    //���������
    srand((unsigned int) time(NULL));
    // ����Ա����������
    vector<Worker> vworker;
    // �Զ�����Ա��
    createWorker(vworker);
    // �����ű�ŵ�Ա������
    multimap<int,Worker> mp;
    // �Զ���ʼ�����ű��
    department(vworker,mp);
    // �ֲ���չʾԱ��
    ShowbyDepart(mp);
    system("pause");
}
