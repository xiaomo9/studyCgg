/*���⺯���������ĳ�����˽����*/
# include<iostream>
using namespace std;

class Person
{
    //����Person����ĺ���goodgay���ˣ������Է��������������
    friend void goodgay(Person &p1);

public:
    string Living_room;

    // ���캯����ʼ��������
    Person()
    {
        Living_room = "����";
        room = "����";
    }

    void print1()
    {
        cout << " �����ǹ����������" << endl;
    }

private:
    string room;

    void print2()
    {
        cout << "������˽����������" << endl;
    }
};

void goodgay(Person &p1)
{
    cout << "�����ǹ�������" << p1.Living_room << endl;
    cout << "������˽������" << p1.room << endl;
}

void test()
{
    Person p1;
    goodgay(p1);
}


int main()
{
    test();

    system("pause");
    return 0;
}