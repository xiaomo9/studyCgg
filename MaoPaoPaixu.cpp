#include <iostream>
using namespace std;

int main(void) 
// 冒泡排序
{ 
    int arr[] = {4,6,1,3,2,8,7,9,5};
    cout << "冒泡排序前的数组：" << endl;
    for (int i = 0; i < sizeof(arr)/sizeof(arr[0]); i++)
    {
        cout << arr[i] << " ";
    }
        cout << endl;
    for (int i = 0; i < (sizeof(arr)/sizeof(arr[0]))-1; i++) // 只需要循环冒泡出n-1个最大值
    {
        for (int j =0; j < (sizeof(arr)/sizeof(arr[0]))-i-1; j++) // 每次冒出一个最大值，下次就可以少循环一次
        {
            if (arr[j] > arr[j+1])
            {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
    cout << "冒泡排序后的数组：" << endl;
    for (int i = 0; i < (sizeof(arr)/sizeof(arr[0])); i++)
    {
        cout << arr[i] << " ";
    } 
        cout << endl;
    system("pause");
    return 0;
}