#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>

class Solution {
public:
    vector<int> getRow(int rowIndex) // ��������������
    {
        vector<vector<int>> c(rowIndex+1); // 
        for(int i = 0; i <= rowIndex; i++)
        {
            // ��ʼ��ÿ�е�ͷ����β������1
            c[i].resize(i+1); // ��Ϊ�����Ǹı�������Ԫ�ص�ֵ��������Ҫ��ǰ���������Ĵ�С����0������䣩
            c[i][0] = c[i][i] = 1;
            for(int j = 1; j <= i-1; j++)
            {
                c[i][j] = c[i-1][j-1] + c[i-1][j];
            }
        }
        return c[rowIndex];
    }       
};

void printfint(int a)
{
    cout << a << endl;
}

int main()
{
    Solution s;
    vector<int> c = s.getRow(4);
    for_each(c.begin(),c.end(),printfint);
    system("pause");
}