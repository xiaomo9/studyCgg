#include<iostream>
#include<climits>
using namespace std;
#include<unordered_set>
#include<unordered_map>

int lengthoflongstr(string s){
    int n = s.size();
    int left = 0;
    int maxlength = 0;
    unordered_map<char,int> charmap;
    for(int right = 0; right < n; ++right){
        if(charmap.find(s[right]) != charmap.end() && charmap[s[right]] >= left){
            left = charmap[s[right]] + 1;
        }
        charmap[s[right]] = right;
        maxlength = max(maxlength,right - left + 1);
    }
    return maxlength;
}

int main(){
    string str = "abcabcab";
    int result = lengthoflongstr(str);
    cout << result << endl;
    system("pause");
    return 0;
}





