#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>

/*
Dijkstra�Ͻ���˹�� ���·������������ĳ���㵽�������е����̾��룩
*/
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<int>> g_dist(n,vector<int>(n,INT_MAX/2)); //����������� ��ά����
        for(auto it : times){  //��ֵ�������
            int x = it[0]-1;
            int y = it[1]-1;
            g_dist[x][y] = it[2];
        }
        vector<int> dis(n,INT_MAX/2);//�������㵽Ŀ���ľ���������
        dis[k-1] = 0; // ��ʼ�ڵ㵽����ľ���
        vector<int> used(n,0); //�˽���Ƿ��Ѿ�������

        //����n�Σ�ÿ���ڵ㵽��ʼ�ڵ�ľ��붼����ֵ
        for(int i =0; i<n ;++i){
            int x = -1;
            // �ҵ�Ŀǰδ��ֵ�ġ�������̵Ľڵ����ĸ�
            for(int y=0; y<n; ++y){
                if(!used[y]&&(dis[y]<dis[x] || x==-1)){
                    x = y; //�ҵ��˽ڵ㸳ֵ��x.
                }
            }
            used[x] = true;
            // ����˽ڵ����ڽڵ㵽��ʼ�ڵ�ľ���
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