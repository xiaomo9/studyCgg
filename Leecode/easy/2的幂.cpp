#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPowerOfTwo(int n) {
        while(n>=2 && n%2!=1)
        {
            n /= 2; 
        }
        return n==1;
    }
};


int main()
{
    Solution s;
    int a = 1;
    cout << s.isPowerOfTwo(a) << endl;
    system("pause");
}