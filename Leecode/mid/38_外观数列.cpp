#include<iostream>
using namespace std;
#include<vector>

/*
��������С���һ����λ�ַ������У��ɵݹ鹫ʽ���壺

countAndSay(1) = "1"
countAndSay(n) �� countAndSay(n-1) ���г̳��ȱ��롣
*/

class Solution {
public:
    string countAndSay(int n) {
        string a = count_say("1",n);
        return a;
    }
    string count_say(string s,int ni){
        if(ni==1) return s;
        string temp;
        int count = 1;
        for(int i = 1;i<s.size();i++){
            if(s[i]==s[i-1]){
                count ++;
                if(i == s.size()-1){
                    string a = to_string(count) + s[i-1];
                    temp.append(a);
                    return count_say(temp,ni-1);
                }
            }
            else{
                string a = to_string(count) + string(1,s[i-1]);
                temp.append(a);
                count = 1;
            }
            if(i == s.size()-1){
                string a = "1" + string(1,s[i]);
                temp.append(a);
                return count_say(temp,ni-1);
            }
        }
        return count_say("11",ni-1);
    }
};

int main(){
    Solution s;
    string a = s.countAndSay(4);
    cout<< a<< endl;
    system("pause");
    return 0;
}