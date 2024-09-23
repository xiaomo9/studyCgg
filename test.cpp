#include <iostream>
using namespace std;
#include<time.h>
#include<vector>
#include<algorithm>
#include<map>

class Solution {
public:
    int firstUniqChar(string s) {
        map<char,int> mp;
        for(char s1 : s)
        {
            mp[s1] ++;
        }
        for(int i = 0; i<s.size(); i++)
        {
            if(mp[s[i]]==1) return i;
        }
        return -1;
    }
};

int main()
{
    system("pause");
}