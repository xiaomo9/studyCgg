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
    ifstream readfile;// ����������
    readfile.open("������test.txt",ios::in|ios::binary); // ���ļ�����λ�úʹ򿪷�ʽ
    if (!readfile.is_open())
    {
        cout << "�ļ���ʧ�ܣ�" << endl;
    }

    Person p;
    readfile.read((char *)&p,sizeof(Person));

    cout << p.name << p.age <<endl;

    system("pause");
    return 0;
}