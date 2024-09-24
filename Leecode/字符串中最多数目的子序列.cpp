/*
����һ���±�� 0 ��ʼ���ַ��� text ����һ���±�� 0 ��ʼ�ҳ���Ϊ 2 ���ַ��� pattern ��
���߶�ֻ����СдӢ����ĸ��

������� text ������λ�ò��� һ�� �ַ������������ַ������� pattern[0] ���� pattern[1] ��
ע�⣬����ַ����Բ����� text ��ͷ���߽�β��λ�á�

���㷵�ز���һ���ַ���text �����������ٸ����� pattern �� ������ ��

������ ָ���ǽ�һ���ַ���ɾ�����ɸ��ַ���Ҳ���Բ�ɾ������ʣ���ַ�����ԭ��˳��õ����ַ�����

*/
#include<iostream>
using namespace std;

class Solution {
public:
    long long maximumSubsequenceCount(string text, string pattern) {
        int num_0 = 0, num_1 = 0;
        long long res = 0;
        for(char s : text)
        {
            if(s==pattern[0]) num_0++;
            if(s==pattern[1]){
                num_1++;
                res += num_0;
            }
        }
        return res + max(num_0 , num_1);
    }
};