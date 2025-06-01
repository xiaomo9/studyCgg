#include<iostream>
using namespace std;
#include<vector>

class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> v1(m,vector<int>(n,0));
        //第一行置1
        for(int i = 0; i<n;i++){
            v1[0][i] = 1;
        }
        //第一列置0
        for(int j = 0; j<m;j++){
            v1[j][0] = 1;
        }
        //开始动态规划路径
        for(int i = 1;i<m; ++i){
            for(int j = 1;j<n ;++j){
                v1[i][j] = v1[i][j-1] + v1[i-1][j];
            }
        }
        return v1[m-1][n-1];
    }
};