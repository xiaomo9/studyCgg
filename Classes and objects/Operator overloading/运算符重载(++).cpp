# include<iostream>
using namespace std;

// �����Լ���������
class MyInt
{
    friend ostream& operator<<(ostream &cout, MyInt int1);
public:
    MyInt()
    {
        this->m_int = 10;
    }

    // ��������ǰ��++�����
    MyInt& operator++()
    {
        m_int ++;
        return *this;
    }

    // �������غ���++�����
    MyInt operator++(int) // �̶��﷨int��ռλ�������ã������ͱ�ʾ��������
    {
        MyInt temp = *this;
        m_int ++;
        return temp;
    }

private:
    int m_int;
};


// �������� << �����
ostream& operator<<(ostream &cout, MyInt int1)
{
    cout << int1.m_int;
    return cout;
}

// ����ǰ��++�����
void test1()
{
    MyInt int1;
    cout << ++int1 << endl;
    cout << int1 << endl;
}

// ���Ժ���++�����
void test2()
{
    MyInt int2;
    cout << int2++ << endl;
    cout << int2 << endl;
}

int main()
{
    test1();
    test2();
    system("pause");
    return 0;
}