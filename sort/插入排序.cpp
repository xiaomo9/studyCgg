#include<iostream>
using namespace std;
#include<time.h>
#define Max 100

clock_t starttime,endtime;
double spendtime;
/*
��������
���Ĺ���ԭ����ͨ�������������У�����δ�������ݣ��������������дӺ���ǰɨ�裬�ҵ���Ӧλ�ò����롣
Ҫ������������������ұ�����������
*/
void insertsort(int arr[])
{
    for(int i = 1; i<Max; ++i)
    {
        int temp = arr[i];
        int j = i-1;
        for(; j>=0 && arr[j]>temp; --j)
        {
            arr[j+1] = arr[j];
        }
        arr[j+1] = temp;
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