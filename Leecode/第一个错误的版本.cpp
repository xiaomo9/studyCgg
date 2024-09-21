#include<iostream>
using namespace std;

/*
���ǲ�Ʒ����Ŀǰ���ڴ���һ���Ŷӿ����µĲ�Ʒ�����ҵ��ǣ���Ĳ�Ʒ�����°汾û��ͨ��������⡣
����ÿ���汾���ǻ���֮ǰ�İ汾�����ģ����Դ���İ汾֮������а汾���Ǵ�ġ�

�������� n ���汾 [1, 2, ..., n]�������ҳ�����֮�����а汾����ĵ�һ������İ汾��

�����ͨ������ bool isBadVersion(version) �ӿ����жϰ汾�� version �Ƿ��ڵ�Ԫ�����г���
ʵ��һ�����������ҵ�һ������İ汾����Ӧ�þ������ٶԵ��� API �Ĵ�����
*/
// The API isBadVersion is defined for you.
bool isBadVersion(int version);

class Solution {
public:

     //���ֲ��ҷ�
    int firstBadVersion(int n) {
        long long int i = 0, j = n+1;
        while(i < j)
        {
            int mid = (i+j)/2;
            if(!isBadVersion(mid)) i = mid;
            if(isBadVersion(mid)) j = mid;
        }
        return j;
    }
};