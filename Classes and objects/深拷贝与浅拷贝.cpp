# include <iostream>
using namespace std;

class Person
{
private:
    /* data */
public:
    int age;
    int *p;

    Person(int ages, int height)
    {
        age = ages;
        // �����µĶ��ڴ�ռ�
        p = new int(height);
        cout << "�вι��캯��" << endl;
    }

    // �������캯��
    Person(const Person &p1)
    {
        age = p1.age;
        //  ����������µ��ڴ�ռ�
        // p = p1.p;
        p = new int(*p1.p);
    }

    ~Person()
    {
        cout << "��������������" << endl;
        if (p != NULL)
        {
            delete p;
            p  = NULL;
        }
    }
};

void test()
{
    Person p1(10,160);
    Person p2(p1);
}

int main()
{
    test();
    system("pause");
    return 0;
}