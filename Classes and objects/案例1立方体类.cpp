# include<iostream>
using namespace std;

// ������������
class Cube
{
    public:
        int l;
        int w;
        int h;
    //�����������
    int volume()
    {
        return l * w *h;
    }

    //�����������
    int area()
    {
        return 2*(l*w + l*h + w*h);
    }

    void judge(class Cube &c)
    {
        if (l==c.l && w == c.w && h==c.h)
            {
                cout << " ������������ͬ" << endl;
            }
            else
            {
                cout << "���������岻��ͬ" << endl;
            }
    }


};

// �ж������������Ƿ���ͬ
void judge(class Cube &a1, class Cube &a2) // ����
{
    if (a1.l==a2.l && a1.w == a2.w && a1.h==a2.h)
    {
        cout << " ������������ͬ" << endl;
    }
    else
    {
        cout << "���������岻��ͬ" << endl;
    }

}

int main()
{
    Cube a1;
    Cube a2;

    a1.l = 3;
    a1.w = 4;
    a1.h = 5;
    a2.l = 3;
    a2.w = 4;
    a2.h = 5;

    judge(a1,a2);
    cout << "a1�������" << a1.area() << "\na1�����" << a1.volume() << endl;

    a1.judge(a2);

    system("pause");
    return 0;

}