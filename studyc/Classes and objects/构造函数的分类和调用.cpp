# include<iostream>
using namespace std;


//����ĳ�ʼ��������
//���ù��캯�����г�ʼ��
//��������������������

class Person
{
private:
    /* data */
public:
    // �޲ι��캯��
    Person()
    {
        cout << "�޲ι��캯���ĵ���" << endl;
    }
    // �вι��캯��
    Person(int a1)
    {
        a = a1;
        cout << "�вι��캯������" << endl;
    }

    // �������캯��
    Person(const Person &p)
    {
        a = p.a;
        cout << "�������캯���ĵ���" << endl;
    }

    // ��������
    ~Person()
    {
        cout << "���������" << endl;
    }

    int a;
};

void test()
{
    Person p1;

}



int main()
{
    // �޲ε���
    Person p1;
    // �вε���
    Person p2(10);
    // ��������
    Person p3(p1);
    system("pause");
}
