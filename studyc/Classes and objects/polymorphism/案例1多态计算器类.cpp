# include<iostream>
using namespace std;

class Calculator
{
public:
    int m_num1;
    int m_num2;

    virtual int getresult() = 0; // ���촿�麯��
};
// ����ӷ�������
class AddCalculator :public Calculator
{
public:
    int getresult()
    {
        return m_num1 + m_num2;
    }
};
// �������������
class DelCalculator :public Calculator
{
public:
    int getresult()
    {
        return m_num1 - m_num2;
    }
};
//����˷�������
class MulCalculator :public Calculator
{
public:
    int getresult()
    {
        return m_num1 * m_num2;
    }
};

void test01()
{
    //���Լӷ�������
    Calculator *ca2 = new AddCalculator;
    ca2 -> m_num1 = 10;
    ca2 -> m_num2 = 20;
    cout << ca2 -> getresult() << endl;
    delete ca2;

    //���Լ���������
    ca2 = new DelCalculator;
    ca2 -> m_num1 = 10;
    ca2 -> m_num2 = 20;
    cout << ca2 -> getresult() << endl;
    delete ca2;

    //���Գ˷�������
    ca2 = new MulCalculator;
    ca2 -> m_num1 = 10;
    ca2 -> m_num2 = 20;
    cout << ca2 -> getresult() << endl;
    delete ca2;

}

int main()
{
    test01();
    system("pause");
    return 0;
}