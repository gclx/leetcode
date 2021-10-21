/**

    给你一个长度为 n 的整数数组，每次操作将会使 n - 1 个元素增加 1 。返回让数组所有元素相等的最小操作次数。

**/

class Solution {
public:
    int minMoves(vector<int>& nums) {
        int Min = INT_MAX;
        for (auto i : nums)
            Min = min(i, Min);
        int ans = 0;
        for (auto i : nums)
            ans += i - Min;
        return ans;
    }
};