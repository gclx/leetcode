/**

	有一个二维矩阵A 其中每个元素的值为0或1。
	移动是指选择任一行或列，并转换该行或列中的每一个值：将所有 0 都更改为 1，将所有 1 都更改为 0。
	在做出任意次数的移动后，将该矩阵的每一行都按照二进制数来解释，矩阵的得分就是这些数字的总和。

	返回尽可能高的分数。


**/

class Solution {
public:

    void flip(vector<vector<int>>& v, bool isRow, int index){
        if (isRow)
            for (int j = 0; j < v[index].size(); j++)
                v[index][j] = !v[index][j];
        else
            for (int i = 0; i < v.size(); i++)
                v[i][index] = !v[i][index];
    }

    int matrixScore(vector<vector<int>>& A) {
        vector<vector<int>> v = A;
        for (int i = 0; i < v.size(); i++)
            if (v[i][0] == 0)
                flip(v, true, i);
        for (int j = 1; j < v[0].size(); j++)
        {
            int cnt = 0;
            for (int i = 0; i < v.size(); i++)
                if (v[i][j] == 0)
                    cnt++;
            if (cnt > v.size()/2)
                flip(v, false, j);
        }

        int ans1 = 0;
        for (int i = 0; i < v.size(); i++)
            for (int j = 0; j < v[i].size(); j++)
                ans1 += v[i][j] * pow(2, (v[i].size())-j-1);
        v = A;
        flip(v, false, 0);
        for (int i = 0; i < v.size(); i++)
            if (v[i][0] == 0)
                flip(v, true, i);
        for (int j = 1; j < v[0].size(); j++)
        {
            int cnt = 0;
            for (int i = 0; i < v.size(); i++)
                if (v[i][j] == 0)
                    cnt++;
            if (cnt > v.size()/2)
                flip(v, false, j);
        }

        int ans2 = 0;
        for (int i = 0; i < v.size(); i++)
            for (int j = 0; j < v[i].size(); j++)
                ans2 += v[i][j] * pow(2, (v[i].size())-j-1);

        return max(ans1, ans2);
    }
};