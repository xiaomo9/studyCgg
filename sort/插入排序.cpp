#include<iostream>
using namespace std;
#include<time.h>
#define Max 100

clock_t starttime,endtime;
double spendtime;
/*
��������
���Ǳ���ÿ��������ÿ�������뵽���ʵ�λ�ã���֤��ߵ���С�ڱ�����
*/
void insertsort(int arr[])
{
    for(int i = 1; i<Max; ++i)
    {
        for(int j=i; j>0 && arr[j]<arr[j-1]; --j)
        {
            int temp = arr[j];
            arr[j] = arr[j-1];
            arr[j-1] = temp;
        }
    }
}


void printarr(int arr[])
{
    for(int i =0; i<Max; ++i)
    {
        cout << arr[i] << endl;
    }
}

int main()
{
    int arr[Max];
    for(int i =0; i< Max; ++i)
    {
        arr[i] = rand() % Max;
    }
    starttime = clock();
    insertsort(arr);
    endtime = clock();
    spendtime = ((double)(endtime - starttime)) / CLK_TCK;
    printarr(arr);
    cout << "spendtime:" << spendtime << "s" << endl;
    system("pause");
}