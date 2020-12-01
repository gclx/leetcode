/**

	给定一个整数数组 nums和一个目标值 target，请你在该数组中找出和为目标值的那两个整数，并返回他们的数组下标。

	你可以假设每种输入只会对应一个答案。但是，数组中同一个元素不能使用两遍。

**/


class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> v;
        map<int, int> m;
        for (int i = 0; i < nums.size(); i++)
            if (m[target-nums[i]])
            {
                v.push_back(m[target-nums[i]]-1);
                v.push_back(i);
                break;
            }
            else
                m[nums[i]] = i+1;
        return v;
    }
};