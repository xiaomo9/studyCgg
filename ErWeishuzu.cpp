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
    string name[3] = {"����","����","����"};
    cout << "��ά��������Ϊ��" << sizeof(arr2) / sizeof(arr2[0]) << endl;
    cout << "��ά��������Ϊ��" << sizeof(arr2[0]) / sizeof(arr2[0][0]) << endl;

    for (int i =0; i < sizeof(arr2) / sizeof(arr2[0]); i++)
    {
        
        int sum = 0;
        for (int j = 0; j < sizeof(arr2[0]) / sizeof(arr2[0][0]); j++)
        {
            sum += arr2[i][j];
        }
        cout << name[i] << "�ĳɼ��ܺ�Ϊ��" << sum << endl;
        cout << endl;
    }


    system("pause");
    return 0;
}