/**

    ����һ���ǿ����飬���ش������� ��������� ����������ڣ��򷵻���������������

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