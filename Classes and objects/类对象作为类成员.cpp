# include<iostream>
using namespace std;

class Phone
{
public:
    string P_name;
    Phone()
    {}
    Phone(string Pname)
    {
        P_name = Pname;
    }
};

class Person
{
public:
    string name;
    Phone M_phone;
    
    // �����б��ʼ��������
    // Person(string mname, string Pname):name(mname), M_phone(Pname) // �ȼ��ڣ�M_phone = Phone(Pname) ��ʽ����
    // {
    // }
    Person(string mname, Phone phone) // ���ȴ���Phone��ҪĬ�ϵĹ��캯������Ϊ��ʱ���޷����ݲ�����
    {
        name = mname;
        M_phone = phone;
    }

};

void test()
{
    // Person p("xiaomo", "HuaWei");
    Phone phone("HuaWei");
    Person p("xiaomo", phone);
    cout << p.name << "����" << p.M_phone.P_name << endl;
}

int main()
{
    test();

    system("pause");
    return 0;
}
