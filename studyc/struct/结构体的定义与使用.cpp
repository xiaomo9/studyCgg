# include <iostream>
# include <string>
using namespace std;

// �ṹ������Զ����������ͣ�
// �Զ����������ͣ�����һЩ���ͼ�����϶��ɵ���������

// ����һ���ṹ��
struct Student

{
    string name;
    int age;
    float score;
};

int main()
{
    Student s1; //ʵ�����ṹ��
    // ʵ��������ṹ������
    s1.name = "����";
    s1.age = 18;
    s1.score = 100;

    cout << s1.name << endl;
    cout << s1.age << endl;
    cout << s1.score << endl;

    system("pause");
    return 0;
}