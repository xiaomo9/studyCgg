# include<iostream>
using namespace std;

// ����������Ʒ����
class AbstractDrink
{
public:
    // ��ˮ
    virtual void Boil() = 0; // ���麯��
    // ����
    virtual void Brew() = 0; // 
    // ���뱭��
    virtual void PourIncup() = 0;
    // ���븨��
    virtual void Addsomething() = 0;

    // ��ʼ������Ʒ
    void domake()
    {
        Boil();
        Brew();
        PourIncup();
        Addsomething();
    }
};

// ���忧������
class coffee :public AbstractDrink
{
    void Boil()
    {
        cout << "-----��������-----" <<endl;
        cout << "��ʼ��ˮ" << endl;
    }

    void Brew()
    {
        cout << "���ݿ���" << endl;
    }

    void PourIncup()
    {
        cout << "�����ȵ��뱭��" << endl;
    }

    void Addsomething()
    {
        cout << "�����Ǻ�ţ��" << endl;
    }
};
// ���������
class tea :public AbstractDrink
{
    void Boil()
    {
        cout << "-----������-----" <<endl;
        cout << "��ʼ��ˮ" << endl;
    }

    void Brew()
    {
        cout << "���ݲ�Ҷ" << endl;
    }

    void PourIncup()
    {
        cout << "����ˮ���뱭��" << endl;
    }

    void Addsomething()
    {
        cout << "�������" << endl;
    }
};

void DoDrink(AbstractDrink *abs)
{
    abs->domake();
}

void test01()
{
    DoDrink(new coffee); //����ָ��ָ���������
    DoDrink(new tea);
}

int main()
{
    test01();
    system("pause");
    return 0;
}

