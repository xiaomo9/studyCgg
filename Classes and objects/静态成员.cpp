# include<iostream>
using namespace std;

/*
���еĶ�����ͬһ����̬��Ա
��̬��Ա�������������������ʼ��
��̬��Ա����ֻ�ܷ��ʾ�̬��Ա����
*/


class Person
{   
    // ��̬��Ա���������������������ʼ��
public:
    static int jingtai;
     int a = 10; 

    // ��̬��Ա����
    static void func1()
    {
        jingtai = 10;
        // a = 100; // ��̬��Ա����ֻ�ܷ��ʾ�̬��Ա����
        cout << "��̬��Ա�����ĵ���" << endl;
    }


};

//��̬��Ա������ʼ��
int Person::jingtai = 100;

void test()
{
    Person p1;
    cout << "���ʾ�̬��Ա����" << endl;
    cout << "p1 = " << p1.jingtai << endl;
    p1.func1();
    cout << "�ڶ��ַ��ʷ�ʽ" << endl;
    cout << "p1 = " <<Person::jingtai << endl;

    

}

int main() 
{
    test();
    system("pause");
    return 0;
}

