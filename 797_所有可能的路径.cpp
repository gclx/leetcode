/**

����һ����?n?���ڵ�� �����޻�ͼ��DAG���������ҳ����дӽڵ� 0?���ڵ� n-1?��·�����������Ҫ���ض�˳��

��ά����ĵ� i �������еĵ�Ԫ����ʾ����ͼ�� i �Žڵ����ܵ������һЩ�ڵ㣬�վ���û����һ������ˡ�

����ע������ͼ���з���ģ����涨�� a��b ��Ͳ��ܴ� b��a ��

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/all-paths-from-source-to-target
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������

**/

class Solution {
public:
    int n;
    vector<vector<int>> path;
    vector<int> p;
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        n = graph.size() - 1;
        dfs(0, graph);
        return path;
    }

    void dfs(int x, vector<vector<int>>& graph){
        p.push_back(x);
        if (x == n){
            path.push_back(p);
            p.pop_back();
            return;
        }
        for (int i = 0; i < graph[x].size(); i++){
            dfs(graph[x][i], graph);
        }
        p.pop_back();
        return;
    }
};