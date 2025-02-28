#include<iostream>
using namespace std;
#include<vector>

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int Row = obstacleGrid.size(); int Column = obstacleGrid[0].size(); //获取行数和列数
        vector<vector<int>> dp(Row,vector<int>(Column,0));//重新规划此路径棋盘
        for(int j = 0;j<Column;++j){
            if(obstacleGrid[0][j] == 1) break;//如果第一行此处是障碍，后面的路将到达不到
            dp[0][j] = 1;
        }
        for(int i = 0; i<Row;i++){
            if(obstacleGrid[i][0] == 1) break;//果第一列此处是障碍，后面的路将到达不到
            dp[i][0] = 1;
        }
        for(int i = 1;i<Row; ++i){
            for(int j = 1; j<Column; ++j){
                if(obstacleGrid[i][j]==1) continue;//此处是障碍，可走路径数为0
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }
        return dp[Row-1][Column-1];
    }
};