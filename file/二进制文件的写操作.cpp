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
    ofstream writefile;
    writefile.open("二进制test.txt",ios::out | ios::binary); // 打开文件位置并确定打开方式
    Person p1 = {"小莫" , 23};
    writefile.write((const char *)&p1,sizeof(Person)); //将要写入的内容写入文件
    writefile.close();

    system("pause");
    return 0;
}