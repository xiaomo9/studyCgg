/*
���һ��Ӣ�۵Ľṹ�壬������Ա���������䡢�Ա𣻴����ṹ�����飬�����д��5��Ӣ�ۡ�
ͨ��ð�������㷨���������е�Ӣ�۰���������������������մ�ӡ�����Ľ��
*/
#include <iostream>
#include<string>
using namespace std;

// ����Ӣ�۽ṹ��
struct Hero
{
    string name;
    int age;
    string sex;
};

// ����ð������
void Bubblesort(struct Hero heros[], int lens)
{
    for (int i = 0; i < lens-1; i++)
    {
        for (int j = 0 ; j< lens-i-1; j++)
        {
            if (heros[j].age > heros[j+1].age)
            {
                struct Hero tump = heros[j];
                heros[j] = heros[j+1];
                heros[j+1] = tump;
            }
        }
    }
}


// �����ӡ�������
void printfHero(struct Hero heros[], int lens)
{
    for (int i = 0; i<lens; i++)
    {
        cout << heros[i].name << "\t" << heros[i].age << "\t" << heros[i].sex << endl;
    }
}

// ������
int main(void)
{
    struct Hero heros[5] = 
    {
        {"����",23,"��"},
        {"����",22,"��"},
        {"�ŷ�",20,"��"},
        {"����",21,"��"},
        {"����",19,"Ů"},
    };
    int lens = sizeof(heros) / sizeof(heros[0]);
    //��Ӣ�۽�����������
    Bubblesort(heros,lens);
    //�����Ӧ����
    printfHero(heros, lens);
    system("pause");
    return 0;
}
