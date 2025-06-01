#include<iostream>
using namespace std;
#include<time.h>
#define Max 10000
/*
选择排序：就是每一轮找到最小或最大数所在的索引，最后将该索引与首位i交换
*/
void selectsort(int arr[])
{
    for(int i = 0; i<Max; ++i)
    {
        int min = arr[i];
        int index = i;
        for(int j = i+1; j<Max; ++j)
        {
            if(min > arr[j])
            {
                min = arr[j];
                index = j;
            }
        }
        arr[index] = arr[i];
        arr[i] = min; 
    }
}

void printarr(int arr[])
{
    for(int i = 0; i< Max; ++i)
    {
        cout << arr[i] << endl;
    }
}


clock_t start, endtime;
double spendtime;
int main()
{
    srand((unsigned int) time(NULL));
    int arr[Max];
    for(int i = 0; i<Max; ++i)
    {
        arr[i] = rand() % Max;
    }

    start = clock();
    selectsort(arr);
    endtime = clock();
    printarr(arr);
    spendtime = ((double)(endtime-start)) / CLK_TCK;
    cout << "time:" << spendtime << "s" << endl;
    system("pause");
}