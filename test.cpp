#include <iostream>
using namespace std;
#include<time.h>
#include<vector>
#include<algorithm>
#include<map>
#include<cmath>
/*
����һ�������ͷ�ڵ� head ��һ������ val ��
����ɾ���������������� Node.val == val �Ľڵ㣬������ �µ�ͷ�ڵ� ��
*/


//쳲�����
int fact(int n)
{
    vector<int> visited(n,-1);
    if(n<=2) return 1;
    if(visited[n] == -1)
    {
        visited[n] = fact(n-1) + fact(n-2);
    }
    return visited[n];
}

int main()
{
    system("pause");
    return 0;
}   