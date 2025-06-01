#include<iostream>
using namespace std;

class Solution {
public:
    bool isPerfectSquare(int num) {
        // 二分查找法
        int left = -1;
        int right = num+1;
        while(left+1 != right)
        {
            int mind = (right-left) / 2 + left; // 防止越界
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