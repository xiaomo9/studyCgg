# include<iostream>
using namespace std;

// �����������븸�࣬������virtual�麯������
// ����ָ�������ָ��������󣨿������ö�̬��

class Animal
{
public:
    virtual void speek()
    {
        cout << "�����ڽУ�" << endl;
    }
};

class Cat :public Animal
{
public:
    void speek()
    {
        cout << "Сè�ڽУ�" << endl;
    }
};

void DoSpeek(Animal &animal)// ʹ�ø����ָ��
{
    animal.speek();
}

void test01()
{   
    Cat cat01;
    DoSpeek(cat01); // ����������븸�ຯ��
}

int main()
{   
    test01();
    system("pause");
    return 0;
}

