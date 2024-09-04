# include<iostream>
using namespace std;

// 创建类
class Person
{
    public:// 公共域  类内外都可以访问
        string name;

    protected: // 保护域 类内可以访问，类外不可以，子类可继承
        string car;
    
    private: // 私有域  类内可以访问，类外不可以，子类不可继承
        string password;

    public:
        void printinfo()
        {// 类内可以访问所有域的内容
            cout << "name: " << name << "  car"  << car << "  password:" << password << endl;
        }

};

int main()
{
    Person xiaomo;
    xiaomo.name = "xiaomo"; //类内只可访问public域内属性与方法。
    xiaomo.printinfo();


    system("pause");
    return 0;
}
