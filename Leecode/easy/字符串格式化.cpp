#include<iostream>
using namespace std;
#include<algorithm>
/*����һ�������Կ�ַ��� s��������ĸ�������ַ������ۺ���ɡ��ַ����� n �����ۺŷֳ� n + 1 �顣
��Ҳ��õ�һ������ k ��

������Ҫ���¸�ʽ���ַ��� s��ʹÿһ����� k ���ַ������˵�һ�飬�����Ա� k �̣�
����Ȼ�����������һ���ַ������⣬����֮�����������ۺţ�����Ӧ�ý�����Сд��ĸת��Ϊ��д��ĸ��

���� ���¸�ʽ���������Կ */

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