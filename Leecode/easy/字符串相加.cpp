#include<iostream>
using namespace std;
#include<algorithm>
class Solution {
public:
    string addStrings(string num1, string num2) {
        string resurt = "";
        int i = num1.size()-1;
        int j = num2.size()-1;
        int add = 0;
        while(i >=0 || j >=0 || add >0)
        {
            int x = i >=0 ? num1[i] - '0' : 0;
            int y = j >=0 ? num2[j] - '0' : 0;
            resurt.push_back((x+y+add)%10 + '0');
            add = (x + y + add) / 10;
            i -= 1;
            j -= 1; 
        }
        reverse(resurt.begin(),resurt.end());
        return resurt;
    }

};
int main()
{
    Solution s;
    string a1 = "129";
    string a2 = "123";
    a2 = s.addStrings(a1,a2);
    cout << a2 << endl;
    system("pause");

}