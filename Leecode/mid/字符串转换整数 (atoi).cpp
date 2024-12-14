#include<iostream>
using namespace std;
#include<vector>
#include<math.h>
class Solution {
public:
    int myAtoi(string s) {
        vector<int> result;
        int flag = false;
        if(s[0]=='-') flag = true;
        int i = flag ? 1 :0;
        if(s[0]=='+') i = 1;
        for(;i<s.size();++i){
            while (s[i]==' '){
                i++;
                if(s[i] == '-') flag = true;
                i++;
            }
            if(!isdigit(s[i])) break;
            int num = s[i] - '0';
            result.push_back(num);
        }
        int arry = result.size()-1;
        long long out = 0;
        for(int a : result){
            out += a*pow(10,arry);
            if(out > pow(2,31)){
                if(flag) return -pow(2,31);
                else return pow(2,31)-1;
            }
            arry--;
        }
        if(flag){
            out = -out;
        }
        return out;
    }
};


int main(){
    Solution s;
    int out = s.myAtoi("-91283472332");
    cout << out <<endl;
    system("pause");
    return 0;
}