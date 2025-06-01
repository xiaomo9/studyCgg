#include<iostream>
using namespace std;
#include<vector>

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n=matrix.size()-1, m = 0;

        while(n>=0 && m<=matrix[0].size()-1){
            if(matrix[n][m] == target) return true;
            else if(matrix[n][m] > target) n--;
            else if(matrix[n][m] < target) m++;
        }
        return false;
    }
};


int main(){
    Solution s;
    vector<vector<int>> v1 = {{-5}};
    bool result = s.searchMatrix(v1,-10);

    cout << result << endl;
    return 0;

}