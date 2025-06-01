#include<iostream>
using namespace std;
#include<vector>

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int Row = grid.size(); int Colum = grid[0].size(); 
        if(Row == 0 || Colum == 0) return 0; // 空矩阵，无对应路径
        vector<vector<int>> dp(Row,vector<int>(Colum));
        dp[0][0] = grid[0][0];
        for(int i = 1; i<Colum; ++i){
            dp[0][i] = dp[0][i-1] + grid[0][i]; //第一行某个位置就是前面位置相加  
        }
        for(int j = 1; j<Row; ++j){
            dp[j][0] = dp[j-1][0] + grid[j][0];
        }
        for(int i = 1; i<Row; i++){
            for(int j = 1 ; j<Colum; ++j){
                if(dp[i][j-1]<=dp[i-1][j]){
                    dp[i][j] = dp[i][j-1] + grid[i][j];
                }
                else{
                    dp[i][j] = dp[i-1][j] + grid[i][j];
                }
            }
        }
        return dp[Row-1][Colum-1];
    }
};