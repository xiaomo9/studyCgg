# include<iostream>
using namespace std;

class Basepage
{
public:
    void Headpage()
    {
        cout << "�����ϱ���" << endl;
    }
    void Footpage()
    {
        cout << "�����±���" << endl;
    }
    void Left()
    {
        cout << "���ǲ����" << endl;
    }
};

// �̳л���ҳ��
class CPP: public Basepage
{
public:
    void content()
    {
        cout << "������C++ѧϰ���ݣ�" << endl;
    }
};

class Java: public Basepage
{
public:
    void content()
    {
        cout << "������JAVAѧϰ���ݣ�" << endl;
    }
};

class Python: public Basepage
{
public:
    void content()
    {
        cout << "������Pythonѧϰ���ݣ�" << endl;
    }
};

void test01()
{
    Java ja1;
    CPP cpp;
    Python py;
    ja1.Headpage();
    ja1.content();
    cpp.Headpage();
    cpp.content();
    py.Headpage();
    py.content();
}

int main()
{
    test01();
    system("pause");
    return 0;
}