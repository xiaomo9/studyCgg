# include<iostream>
using namespace std;
# include<fstream>

class Person
{
public:
    char name[64];
    int age;
};

int main()
{
    ifstream readfile;// 创建流对象
    readfile.open("二进制test.txt",ios::in|ios::binary); // 打开文件所在位置和打开方式
    if (!readfile.is_open())
    {
        cout << "文件打开失败！" << endl;
    }

    Person p;
    readfile.read((char *)&p,sizeof(Person));

    cout << p.name << p.age <<endl;

    system("pause");
    return 0;
}