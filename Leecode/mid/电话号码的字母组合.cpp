#include<iostream>
using namespace std;
#include<vector>

class Solution {
private:
    const string letterMap[10] = {
        "", // 0
        "", // 1
        "abc", // 2
        "def", // 3
        "ghi", // 4
        "jkl", // 5
        "mno", // 6
        "pqrs", // 7
        "tuv", // 8
        "wxyz", // 9
    };
public:
    vector<string> result;
    string s;
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) {
            return result;
        }
        backtracking(digits,0);
        return result;
    }

    void backtracking(string digits,int index){
        if(index == digits.size()){
            result.push_back(s);
            return;
        }
        int indexx = digits[index] - '0';
        string letter = letterMap[indexx];
        for(int i = 0; i<letter.size();i++){
            s.push_back(letter[i]);
            backtracking(digits,index++);
            s.pop_back();
        }
    }
};
