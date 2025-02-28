#include<iostream>
using namespace std;
#include<algorithm>
/*给定一个许可密钥字符串 s，仅由字母、数字字符和破折号组成。字符串由 n 个破折号分成 n + 1 组。
你也会得到一个整数 k 。

我们想要重新格式化字符串 s，使每一组包含 k 个字符，除了第一组，它可以比 k 短，
但仍然必须包含至少一个字符。此外，两组之间必须插入破折号，并且应该将所有小写字母转换为大写字母。

返回 重新格式化的许可密钥 */

class Solution {
public:
    string licenseKeyFormatting(string s, int k) {
        string res;
        int n =0;
        for(int i = s.size()-1; i>=0; --i)
        {
            if(s[i] != '-'){
                res.push_back(toupper(s[i]));
                n++;
                if(n % k == 0)
                res.push_back('-');
            }
        }
        if(res.back()=='-'){
            res.pop_back();
        }
        reverse(res.begin(),res.end());

        return res;
    }
};

int main()
{

    string s = "---";
    Solution s1;
    string s2;
    int k = 3;
    s2 = s1.licenseKeyFormatting(s,k);
    cout << s2 << endl; 
    system("pause");

}