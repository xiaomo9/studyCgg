# include<iostream>
using namespace std;

class Person
{
    // �����෽���ı�˽�����ԵĿɶ���д��
    public:
    void setname(string name1)
    {
        name = name1;
    }

    void printname()
    {
        cout << "name:" << name << endl;
    }

    void printage()
    {
        cout << "age:" << age << endl;
    }

    void setIDo(string ido)
    {
        Ido = ido;
    }

    private:
        string name;  // ���ֿɶ���д
        int age = 23;      // ����ֻ��
        string Ido;   // ż��ֻд

};


int main ()
{
    Person p;
    p.setname("xiaomo");
    p.printname();
    p.setIDo("����");
    p.printage();
    system("pause");
    return 0;
}