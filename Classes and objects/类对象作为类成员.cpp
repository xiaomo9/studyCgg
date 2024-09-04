# include<iostream>
using namespace std;

class Phone
{
public:
    string P_name;
    Phone()
    {}
    Phone(string Pname)
    {
        P_name = Pname;
    }
};

class Person
{
public:
    string name;
    Phone M_phone;
    
    // 属性列表初始化类属性
    // Person(string mname, string Pname):name(mname), M_phone(Pname) // 等价于：M_phone = Phone(Pname) 隐式调用
    // {
    // }
    Person(string mname, Phone phone) // 首先创建Phone需要默认的构造函数（因为这时候无法传递参数）
    {
        name = mname;
        M_phone = phone;
    }

};

void test()
{
    // Person p("xiaomo", "HuaWei");
    Phone phone("HuaWei");
    Person p("xiaomo", phone);
    cout << p.name << "拿着" << p.M_phone.P_name << endl;
}

int main()
{
    test();

    system("pause");
    return 0;
}
