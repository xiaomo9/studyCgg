# include <iostream>
# include <string>
using namespace std;

int main(void)
{
    int arr2[][3] = 
    {
        {78,80,90},
        {88,90,100},
        {98,100,100}
    };
    string name[3] = {"张三","李四","王五"};
    cout << "二维数组行数为：" << sizeof(arr2) / sizeof(arr2[0]) << endl;
    cout << "二维数组列数为：" << sizeof(arr2[0]) / sizeof(arr2[0][0]) << endl;

    for (int i =0; i < sizeof(arr2) / sizeof(arr2[0]); i++)
    {
        
        int sum = 0;
        for (int j = 0; j < sizeof(arr2[0]) / sizeof(arr2[0][0]); j++)
        {
            sum += arr2[i][j];
        }
        cout << name[i] << "的成绩总和为：" << sum << endl;
        cout << endl;
    }


    system("pause");
    return 0;
}