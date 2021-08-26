/**

给你一个有?n?个节点的 有向无环图（DAG），请你找出所有从节点 0?到节点 n-1?的路径并输出（不要求按特定顺序）

二维数组的第 i 个数组中的单元都表示有向图中 i 号节点所能到达的下一些节点，空就是没有下一个结点了。

译者注：有向图是有方向的，即规定了 a→b 你就不能从 b→a 。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/all-paths-from-source-to-target
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

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