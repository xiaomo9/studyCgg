/*
����һ��������дһ���������ж����Ƿ��� 3 ���ݴη�������ǣ����� true �����򣬷��� false ��

���� n �� 3 ���ݴη������㣺�������� x ʹ�� n == 3x


*/

#include<iostream>
using namespace std;
#include<vector>

class Solution {
public:
    bool isPowerOfThree(int n) {
        while(n && n % 3 == 0)
        {
            n /= 3;
        }
        return n == 1;
    }
};

int main()
{
    Solution s;
    s.isPowerOfThree(27);
}


