/**

	给定一个按照升序排列的整数数组 nums，和一个目标值 target。找出给定目标值在数组中的开始位置和结束位置。

	如果数组中不存在目标值 target，返回?[-1, -1]。


**/


class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> v;
        int st = lower_bound(nums.begin(), nums.end(), target) - nums.begin();
        int end = upper_bound(nums.begin(), nums.end(), target) - nums.begin();
        if (st == end)
            v.push_back(-1), v.push_back(-1);
        else if (end == nums.size())
            v.push_back(st), v.push_back(nums.size()-1);
        else
            v.push_back(st), v.push_back(end-1);
        return v;
    }
};