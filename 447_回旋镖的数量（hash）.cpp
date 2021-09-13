/**

    给定平面上n 对 互不相同 的点points ，其中 points[i] = [xi, yi] 。回旋镖 是由点(i, j, k) 表示的元组 ，其中i和j之间的距离和i和k之间的距离相等（需要考虑元组的顺序）。

    返回平面上所有回旋镖的数量。

    来源：力扣（LeetCode）
    链接：https://leetcode-cn.com/problems/number-of-boomerangs
    著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

**/

class Solution {
public:
    int numberOfBoomerangs(vector<vector<int>>& points) {
        int n = points.size();
        double eps = 1e-6;
        vector<pair<double, int>> v[n];
        for (int i = 0; i < n; i++){
            for (int j = 0; j < n; j++){
                double dis = sqrt(pow(abs(points[i][0]-points[j][0]), 2) + pow(abs(points[i][1]-points[j][1]), 2));
                bool flag = false;
                for (int k = 0; k < v[i].size(); k++)
                    if (fabs(v[i][k].first - dis) < eps){
                        v[i][k].second++;
                        flag = true;
                        break;
                    }
                if (!flag)
                    v[i].push_back(make_pair(dis, 1));
            }
        }
        long long ans = 0;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < v[i].size(); j++)
                ans += v[i][j].second * (v[i][j].second-1);
        return ans;
    }
};