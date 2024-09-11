#include<iostream>
using namespace std;
#define Max 1000
#include<time.h>
// √∞≈›≈≈–Ú
void bubblesort(int arr[])
{
    for(int i = 0; i<Max-1; ++i)
    {
        for(int j =0; j<Max-i-1; ++j)
        {
            if(arr[j] >arr[j+1])
            {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }

}
void printarr(int arr[])
{
    for(int i = 0; i<Max; ++i)
    {
        cout << arr[i] << endl;
    }
}

int main()
{
    int arr[Max];
    srand((unsigned int)time(NULL));
    for(int i = 0; i<Max; ++i)
    {
        arr[i] = rand() % Max;
    }
    clock_t start, end;
    start = clock(); // ±÷”¥Úµ„
    bubblesort(arr);
    end = clock();
    double speedtime = ((double)(end-start))/CLK_TCK;
    printarr(arr);
    cout << "time:" << speedtime << endl;
    system("pause");
}