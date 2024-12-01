#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>
#include<math.h>
/*
给你一个 32 位的有符号整数 x ，返回将 x 中的数字部分反转后的结果。

如果反转后整数超过 32 位的有符号整数的范围 [?2^31,  2^31 ? 1] ，就返回 0。

假设环境不允许存储 64 位整数（有符号或无符号）。
 
*/

class Solution {
public:
    int reverse(int x) {
        vector<int> arr;
        bool flag = false;
        if(x<0) flag = true;
        x = abs(x);
        while (x!=0)
        {
            int unit = x %10;
            x /= 10;
            arr.push_back(unit);
        }
        int result = 0;
        int arry = arr.size()-1;
        for(int a : arr){
            result += a*pow(10,arry);
            if(result>(pow(2,31)-1)||result<pow(-2,31)) return 0;
            arry--;
        }
        if(flag) result = -result;
        return result;
    }
};


int main(){
    Solution s;
    int a = -321;
    int b = s.reverse(a);
    cout << b << endl;
    system("pause");
    return 0;
}