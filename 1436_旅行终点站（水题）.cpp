/**

    给你一份旅游线路图，该线路图中的旅行线路用数组 paths 表示，其中 paths[i] = [cityAi, cityBi] 表示该线路将会从 cityAi 直接前往 cityBi 。请你找出这次旅行的终点站，即没有任何可以通往其他城市的线路的城市。

    题目数据保证线路图会形成一条不存在循环的线路，因此恰有一个旅行终点站。

    来源：力扣（LeetCode）
    链接：https://leetcode-cn.com/problems/destination-city
    著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

**/

class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        vector<string> s, t;
        for (auto i : paths){
            s.push_back(i[0]);
            t.push_back(i[1]);
        }
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        int poss= 0, post = 0;
        while (1){
            //cout << s[poss] << " " << t[post] << endl;
            if (s[poss] == t[post]){
                poss++, post++;
            } else {
                if (s[poss] < t[post])
                    poss++;
                else
                    return t[post];
            }
            if (poss == s.size())
                return t[post];
        }
        return "";
    }
};