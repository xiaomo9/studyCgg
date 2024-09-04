# include<iostream>
using namespace std;

class Person
{
public:
    int M_age;
    int M_menoy;

    Person()
    {
        this->M_age = 10;
        this->M_menoy = 2000;
    }
    // 左移运算符无法使用成员函数重载
};


ostream & operator<< (ostream &cout, Person &p)
{                          
    cout << p.M_age << "  " << p.M_menoy << endl;
    return cout;
} 

void test01()
{
    Person p1;

    cout << p1 ;
}

int main()
{
    test01();

    system("pause");
    return 0;

}

