# include<iostream>
using namespace std;

class Person
{
    // 利用类方法改变私有属性的可读可写性
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
        string name;  // 名字可读可写
        int age = 23;      // 年龄只读
        string Ido;   // 偶像只写

};


int main ()
{
    Person p;
    p.setname("xiaomo");
    p.printname();
    p.setIDo("许嵩");
    p.printage();
    system("pause");
    return 0;
}