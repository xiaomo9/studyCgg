# include<iostream>
using namespace std;

//���ȶ���һ���࣬���ں�������Ԫ
class Budding;
class Goodgay
{
public:
    void visit();
    Goodgay();
    Budding * budding;
};


class Budding
{
friend class Goodgay;
public:
    string sittingroom;

    Budding();


private:
    string bedroom;
};

// �����ⶨ����Ĺ��캯��
Budding::Budding()
{
    this->bedroom = "����";
    this->sittingroom = "����";
}

Goodgay::Goodgay()
{
    budding = new Budding;
}

void Goodgay::visit()
{
    cout << "�����ǹ�������" << budding->sittingroom << endl;
    cout << "������˽������" << budding->bedroom << endl;
}


void test()
{
    Goodgay g1;
    g1.visit();

}

int main()
{
    test();

    system("pause");
    return 0;
}