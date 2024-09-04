#include <iostream>
using namespace std;

// ����ģ��
template <class T>
void myswap(T &a, T &b)
{
    T temp = a;
    a = b;
    b = temp;
}


// ѡ������ģ��
template <class T>
void mysort(T arry, int len)
{
    for (int i = 0; i < len-1; i++)
    {
        int min = i; // �ҵ��˴�ѭ����С��ֵ������
        for (int j = i+1; j < len; j++)
        {
            if(arry[min] > arry[j])
            {
                min = j;
            }
        }
        if(min !=i)
        {
            myswap(arry[i],arry[min]);
        }
    }
}

// չʾ��������
template<class T>
void Show_arry(T arry, int len)
{
    for(int i = 0; i<len; i++)
    {
        cout << arry[i] << " ";
    }
    cout << endl;

}

void test1()
{
    char chararry[] = "cdabfe";
    int arr_len = sizeof(chararry) / sizeof(chararry[0]);
    mysort(chararry,arr_len);
    Show_arry(chararry, arr_len);

}

void test2()
{
    int intarry[] = {1,4,3,2,9,8,7};
    int arr_len = sizeof(intarry)/ sizeof(intarry[0]);
    mysort(intarry, arr_len);
    Show_arry(intarry, arr_len);
}

int main()
{
    test1();
    test2();
    system("pause");
    system("cls");
}