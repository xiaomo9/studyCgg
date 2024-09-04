# include "MyArray.hpp"

void printf_arr(MyArray<int> &arr)
{
    for(int i = 0;i<arr.get_size(); i++)
    {
        cout << arr[i] << endl;
    }
}

int main()
{
    MyArray<int> arr1(10);

    for(int i =0; i<10;i++)
    {
        arr1.push_back(i);
    }

    printf_arr(arr1);
    arr1.del_back();
    printf_arr(arr1);
    

    system("pause");
    return 0;

}