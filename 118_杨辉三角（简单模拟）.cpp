/**

	给定一个非负整数 numRows，生成杨辉三角的前 numRows 行。

**/

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> v;
        if (numRows == 0)
            return v;
        vector<int> last;
        last.push_back(1);
        v.push_back(last);
        if (numRows == 1)
            return v;
        last.push_back(1);
        v.push_back(last);
        for (int i = 2; i < numRows; i++)
        {
            vector<int> now;
            now.push_back(1);
            for (int j = 1; j < i; j++)
                now.push_back(last[j-1]+last[j]);
            now.push_back(1);
            v.push_back(now);
            last = now;
        }
        return v;
    }
};