#include<iostream>
using namespace std;
#include<algorithm>

class Solution {
public:
    bool isPalindrome(string s)
    {
        string sch;
        //�Ƚ������������ĸ�����ֱ�������
        for(char ch : s)
        {
            if(isalnum(ch))
            {
                sch += tolower(ch); //����ĸתΪСд�����޷�ת������ԭ�ַ���
            }
        }

        string sch_rev = sch;
        reverse(sch_rev.begin(),sch_rev.end()); //���ַ���ȡ��

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