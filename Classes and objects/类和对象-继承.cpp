# include<iostream>
using namespace std;

const double PI = 3.14;

// ����Բ��
class Circle
{
    // ˽������
    private:
    // ��������
    public:
    double radius;

    double calaulate()
    {
        return 2*PI*radius;
    }
};


// ����ѧ����

class Student
{
    //����������
    public:
    string name;
    string ID;
    //�����෽��
    void setname(string name1)
    {
        name = name1;
    }

    void setID(string ID1)
    {
        ID  = ID1;
    }

    void printinfo()
    {
        cout << "������ " << name << "   ID:" << ID << endl;
    }
};


int main()
{
    //ʵ���� ѧ����

    Student xiaomo;
    xiaomo.setname("chenadsasao");
    xiaomo.setID("120224");

    xiaomo.printinfo();

    system("pause"); 
    return 0;
}