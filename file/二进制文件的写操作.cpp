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
    writefile.open("������test.txt",ios::out | ios::binary); // ���ļ�λ�ò�ȷ���򿪷�ʽ
    Person p1 = {"СĪ" , 23};
    writefile.write((const char *)&p1,sizeof(Person)); //��Ҫд�������д���ļ�
    writefile.close();

    system("pause");
    return 0;
}