/**

    符合下列属性的数组 arr 称为 山峰数组（山脉数组） ：

    arr.length >= 3
    存在 i（0 < i < arr.length - 1）使得：
    arr[0] < arr[1] < ... arr[i-1] < arr[i]
    arr[i] > arr[i+1] > ... > arr[arr.length - 1]
    给定由整数组成的山峰数组 arr ，返回任何满足 arr[0] < arr[1] < ... arr[i - 1] < arr[i] > arr[i + 1] > ... > arr[arr.length - 1] 的下标 i ，即山峰顶部。

    来源：力扣（LeetCode）
    链接：https://leetcode-cn.com/problems/B1IidL
    著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

**/


class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int n = arr.size();
        int l = 0, r = n;
        while (l <= r){
            int mid = (l+r) / 2;
            if (arr[mid] > arr[mid-1] && arr[mid] > arr[mid+1])
                return mid;
            else if (arr[mid] < arr[mid+1])
                l = mid+1;
            else if (arr[mid] < arr[mid-1])
                r = mid;
        }
        return 0;
    }
};