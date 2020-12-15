/**

	给定一个非负整数N，找出小于或等于N的最大的整数，同时这个整数需要满足其各个位数上的数字是单调递增。

	（当且仅当每个相邻位数上的数字x和y满足x <= y时，我们称这个整数是单调递增的。）

**/

class Solution {
public:
    int monotoneIncreasingDigits(int N) {
        vector<int> v;
        int flag = 0;
        while (N)
        {
            int after = N % 10 + flag;
            int before = N / 10 % 10;
            if (after < before)
                flag = -1, v.push_back(-1);
            else
                flag = 0, v.push_back(after);
            N /= 10;
        }
        for (int i = v.size()-1; i >= 0; i--)
            if (v[i] == -1)
            {
                for (int j = 0; j <= i; j++)
                    v[j] = 9;
                break;
            }
        int ans = 0;
        for (int i = v.size()-1; i >= 0; i--)
            ans = ans * 10 + v[i];
        return ans;
    }
};