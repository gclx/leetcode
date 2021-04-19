/**
    给你一个数组 nums?和一个值 val，你需要 原地 移除所有数值等于?val?的元素，并返回移除后数组的新长度。

    不要使用额外的数组空间，你必须仅使用 O(1) 额外空间并 原地 修改输入数组。

    元素的顺序可以改变。你不需要考虑数组中超出新长度后面的元素。

**/

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int cnt = 0;
        int len = nums.size();
        for (int i = 0; i < len; i++){
            int tmp;
            if (nums[i] == val){
                if (i + cnt >= len-1)
                    return i;
                tmp = nums[i];
                nums[i] = nums[len-1-cnt];
                nums[len-1-cnt] = tmp;
                cnt++;
                i--;
            }
            if (i == len-1)
                return len;
        }
        return 0;
    }
};