#include <iostream>
using namespace std;
#include<time.h>
#include<vector>
#include<algorithm>
#include<map>
#include<cmath>
/*
给你一个链表的头节点 head 和一个整数 val ，
请你删除链表中所有满足 Node.val == val 的节点，并返回 新的头节点 。
*/


//斐波那契
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