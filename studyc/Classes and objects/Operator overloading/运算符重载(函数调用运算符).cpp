# include<iostream>
using namespace std;

class Myprintf
{
public:
    void operator() (string name)
    {
        cout << "��������ǣ�" << name <<endl;
    }
};


class Myadd
{
public:
    int operator()  (int a, int b)
    {
        return a+b;
    }
};

void test01()
{
    Myprintf print1;
    print1("СĪ");
}

void test02()
{
    Myadd add;
    int c = add(10,20);
    cout << "c = " << c << endl;
}

int main()
{
    test01();
    test02();
    system("pause");
    return 0;

}