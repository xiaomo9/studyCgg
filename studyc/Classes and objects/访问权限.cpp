# include<iostream>
using namespace std;

// ������
class Person
{
    public:// ������  �����ⶼ���Է���
        string name;

    protected: // ������ ���ڿ��Է��ʣ����ⲻ���ԣ�����ɼ̳�
        string car;
    
    private: // ˽����  ���ڿ��Է��ʣ����ⲻ���ԣ����಻�ɼ̳�
        string password;

    public:
        void printinfo()
        {// ���ڿ��Է��������������
            cout << "name: " << name << "  car"  << car << "  password:" << password << endl;
        }

};

int main()
{
    Person xiaomo;
    xiaomo.name = "xiaomo"; //����ֻ�ɷ���public���������뷽����
    xiaomo.printinfo();


    system("pause");
    return 0;
}
