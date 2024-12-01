#include<iostream>
using namespace std;
#include<vector>

class Solution {
public:
    string convert(string s, int numRows) {
        vector<string> v1(numRows+1);
        int flag = -1;
        int i = 0;
        if(numRows==1) return s;
        for(char ca : s){
            v1[i].push_back(ca);
            if(i==0 || i == (numRows-1)){
                flag = -flag;
            }
            i += flag;
        }
        string result;
        for(string c : v1){
            result += c;
        }
        return result;
    }
};


int main()
{
    string s = "AB";
    vector<string> v1 = {"acad","acd","wvwrvte"};
    vector<string>::iterator it = v1.begin();
    Solution s2;
    string s1 =  s2.convert(s,1);
    cout << s1 << endl;
    system("pause");
    return 0;
}