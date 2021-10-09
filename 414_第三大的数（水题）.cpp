/**

    给你一个非空数组，返回此数组中 第三大的数 。如果不存在，则返回数组中最大的数。

**/

class Solution {
public:
    int thirdMax(vector<int>& nums) {
        sort(nums.rbegin(), nums.rend());
        int n = unique(nums.begin(), nums.end()) - nums.begin();
        if (n >= 3)
            return nums[2];
        else
            return nums[0];
    }
};