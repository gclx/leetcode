/**

    ����ƽ����n �� ������ͬ �ĵ�points ������ points[i] = [xi, yi] �������� ���ɵ�(i, j, k) ��ʾ��Ԫ�� ������i��j֮��ľ����i��k֮��ľ�����ȣ���Ҫ����Ԫ���˳�򣩡�

    ����ƽ�������л����ڵ�������

    ��Դ�����ۣ�LeetCode��
    ���ӣ�https://leetcode-cn.com/problems/number-of-boomerangs
    ����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������

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