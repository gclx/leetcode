/**

    给你两个 没有重复元素 的数组 nums1 和 nums2 ，其中nums1 是 nums2 的子集。

    请你找出 nums1 中每个元素在 nums2 中的下一个比其大的值。

    nums1 中数字 x 的下一个更大元素是指 x 在 nums2 中对应位置的右边的第一个比 x 大的元素。如果不存在，对应位置输出 -1 。

    来源：力扣（LeetCode）
    链接：https://leetcode-cn.com/problems/next-greater-element-i
    著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

**/

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> v;
        for (int i = 0; i < nums1.size(); i++){
            int pos = find(nums2.begin(), nums2.end(), nums1[i]) - nums2.begin() + 1;
            //cout << pos << endl;
            if (pos >= nums2.size()){
                v.push_back(-1);
                continue;
            }
            for (pos; pos < nums2.size(); pos++)
                if (nums2[pos] > nums1[i]){
                    v.push_back(nums2[pos]);
                    break;
                }
                else if (pos == nums2.size()-1)
                    v.push_back(-1);
        }
        return v;
    }
};