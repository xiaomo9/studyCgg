#include<iostream>
using namespace std;
#include<vector>


/*
����һ������ n ������ 0 <= i <= n �е�ÿ�� i ������������Ʊ�ʾ�� 1 �ĸ��� ������һ������Ϊ n + 1 ������ ans ��Ϊ�𰸡�����һ������ n ������ 0 <= i <= n �е�ÿ�� i ��
����������Ʊ�ʾ�� 1 �ĸ��� ������һ������Ϊ n + 1 ������ ans ��Ϊ�𰸡�
*/
class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> bits;
        for(int i = 0; i<n+1; i++)
        {
            int j = i;
            int count = 0;
            while(j != 0)
            {
                j = j&(j-1); // �������һλ��1
                count ++; 
            }
            bits.push_back(count);
        }
        return bits;
    }
};


int main()
{
    Solution S;
    
}