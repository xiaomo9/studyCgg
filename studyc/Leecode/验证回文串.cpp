#include<iostream>
using namespace std;
#include<algorithm>

class Solution {
public:
    bool isPalindrome(string s)
    {
        string sch;
        //先将里面的所有字母和数字遍历出来
        for(char ch : s)
        {
            if(isalnum(ch))
            {
                sch += tolower(ch); //将字母转为小写，若无法转换返回原字符。
            }
        }

        string sch_rev = sch;
        reverse(sch_rev.begin(),sch_rev.end()); //对字符串取反

        if(sch == sch_rev)
        {
            return true;
        }
        else{return false;}

    }
};


int main()
{
    string str = "abbaa";
    Solution s;
    bool flag = s.isPalindrome(str);
    cout << flag << endl;
    system("pause");

}