#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>

/*
Dijkstra迪杰特斯拉 最短路径搜索（搜索某个点到其余所有点的最短距离）
*/
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<int>> g_dist(n,vector<int>(n,INT_MAX/2)); //声明各点距离 二维矩阵
        for(auto it : times){  //赋值各点距离
            int x = it[0]-1;
            int y = it[1]-1;
            g_dist[x][y] = it[2];
        }
        vector<int> dis(n,INT_MAX/2);//声明各点到目标点的距离向量。
        dis[k-1] = 0; // 起始节点到自身的距离
        vector<int> used(n,0); //此结点是否已经被计算

        //遍历n次，每个节点到初始节点的距离都被赋值
        for(int i =0; i<n ;++i){
            int x = -1;
            // 找到目前未赋值的、距离最短的节点是哪个
            for(int y=0; y<n; ++y){
                if(!used[y]&&(dis[y]<dis[x] || x==-1)){
                    x = y; //找到此节点赋值给x.
                }
            }
            used[x] = true;
            // 计算此节点相邻节点到初始节点的距离
            for(int y = 0;y<n; ++y){
                dis[y] = min(dis[x]+g_dist[x][y],dis[y]);
            }
        }
        int result = *max_element(dis.begin(),dis.end());
        return result == INT_MAX/2 ? -1 : result; 
    }
};


int main()
{
    vector<vector<int>> matir = {
        {1,2,1},{2,3,3},{3,4,1},{2,1,5}
        };
    Solution s;
    int result = s.networkDelayTime(matir,4,2);
    cout << result << endl;
    system("pause");
}