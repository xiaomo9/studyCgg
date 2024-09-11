#include<iostream>
using namespace std;

/*

*/

void quitsort(int arr[], int start, int end)
{   
    if(start>=end) return; //递归一定要有退出语句，并且要第一时间写出来
    int i = start;
    int j = end;
    int base = arr[i];
    while(i<j)
    {
        while(i<j && arr[j]>base) j--;
        if(i<j) 
        {
            arr[i] = arr[j];
            i++;
        }
        while(i<j && arr[i]<base) i++;
        if(i<j)
        {
            arr[j] = arr[i];
            j--;
        }
    }
    arr[i] = base;
    quitsort(arr,start,i-1);
    quitsort(arr,i+1,end);

}

void printarr(int arr[], int length)
{
    for(int i = 0; i<length; i++)
    {
        cout << arr[i] << endl;
    }
}

int main()
{
    int arr[] = {2,1,7,6,8,9,5,4,3,0};
    int length = sizeof(arr)/sizeof(arr[0]);
    quitsort(arr,0,length-1);
    printarr(arr,length);
    system("pause");
}