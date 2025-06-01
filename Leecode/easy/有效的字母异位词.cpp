#include<iostream>
using namespace std;
#include<vector>
#include<unordered_set>

class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> v(26,0);
        if(s.size() != t.size()) return 0;
        for(char a : s){
            v[a - 'a']++;
            }
        for(char b : t){
            v[b - 'a']--;
            if(v[b-'a'] < 0) return 0;
            }
        return 1;
    }
};

int main()
{
    Solution s;
    cout << s.isAnagram("abcde","bcdaq") << endl;
    system("pause");
}