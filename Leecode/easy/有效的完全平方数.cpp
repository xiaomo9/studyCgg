#include<iostream>
using namespace std;

class Solution {
public:
    bool isPerfectSquare(int num) {
        // ���ֲ��ҷ�
        int left = -1;
        int right = num+1;
        while(left+1 != right)
        {
            int mind = (right-left) / 2 + left; // ��ֹԽ��
            long long squrt = (long)mind*mind;
            if(squrt > num) right = mind;
            if(squrt <= num) left = mind;
        }
        return left*left == num;
    }
};

int main()
{
    Solution s;
    cout << s.isPerfectSquare(122) << endl;
    system("pause");
}