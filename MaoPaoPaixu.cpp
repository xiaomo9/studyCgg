#include <iostream>
using namespace std;

int main(void) 
// ð������
{ 
    int arr[] = {4,6,1,3,2,8,7,9,5};
    cout << "ð������ǰ�����飺" << endl;
    for (int i = 0; i < sizeof(arr)/sizeof(arr[0]); i++)
    {
        cout << arr[i] << " ";
    }
        cout << endl;
    for (int i = 0; i < (sizeof(arr)/sizeof(arr[0]))-1; i++) // ֻ��Ҫѭ��ð�ݳ�n-1�����ֵ
    {
        for (int j =0; j < (sizeof(arr)/sizeof(arr[0]))-i-1; j++) // ÿ��ð��һ�����ֵ���´ξͿ�����ѭ��һ��
        {
            if (arr[j] > arr[j+1])
            {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
    cout << "ð�����������飺" << endl;
    for (int i = 0; i < (sizeof(arr)/sizeof(arr[0])); i++)
    {
        cout << arr[i] << " ";
    } 
        cout << endl;
    system("pause");
    return 0;
}