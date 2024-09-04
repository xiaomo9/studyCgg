#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>

class Solution {
public:
    vector<int> getRow(int rowIndex) // 返回向量的容器
    {
        vector<vector<int>> c(rowIndex+1); // 
        for(int i = 0; i <= rowIndex; i++)
        {
            // 初始化每行的头部和尾部都是1
            c[i].resize(i+1); // 因为我们是改变容器内元素的值，所以需要提前给定容器的大小（即0数据填充）
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