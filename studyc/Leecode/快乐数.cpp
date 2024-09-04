#include<iostream>
using namespace std;
#include<unordered_set>  //哈希表集合头文件
#include<vector>

class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> s1;
        while(s1.find(n) == s1.end())
        {
            s1.insert(n);
            int sum = 0;
            while(n>0)
            {
                int digit = n % 10;
                sum += digit * digit;
                n /= 10;
            }
            n = sum;
            if(n == 1)
            {
                return true;
            }
        }
        return false;
    }
};


int main()
{
    Solution s;
    bool a = s.isHappy(19);
    cout << a << endl;
    system("pause");
    return 0;
}