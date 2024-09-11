#include<iostream>
using namespace std;
#include<time.h>
#define Max 100

clock_t starttime,endtime;
double spendtime;
/*
插入排序：
它的工作原理是通过构建有序序列，对于未排序数据，在已排序序列中从后向前扫描，找到相应位置并插入。
要插入数的左边是有序，右边是无序序列
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