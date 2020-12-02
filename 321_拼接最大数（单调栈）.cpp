/**
	给定长度分别为m和n的两个数组，其元素由0-9构成，表示两个自然数各位上的数字。现在从这两个数组中选出 k (k <= m + n)个数字拼接成一个新的数，要求从同一个数组中取出的数字保持其在原数组中的相对顺序。

**/



class Solution {
public:

    vector<int> maxSubsequence(vector<int>& nums, int k) {
        const int maxn = 1e3+7;
        int s[maxn];
        int top = -1;
        int away = nums.size() - k;
        for (int i = 0; i < nums.size(); i++)
        {
            while (top >= 0 && nums[i] > s[top] && away > 0)
                top--, away--;
            if (top+1 < k)
                s[++top] = nums[i];
            else
                away--;
        }
        vector<int> ans;
        for (int i = 0; i <= top; i++)
            ans.push_back(s[i]);
        return ans;
    }

    int cmp(vector<int> v1, vector<int> v2, int pos1, int pos2){
        int n = v1.size() - pos1;
        int m = v2.size() - pos2;
        for (int i = 0; i < min(n, m); i++, pos1++, pos2++)
        {
            if (v1[pos1] < v2[pos2])
                return -1;
            if (v1[pos1] > v2[pos2])
                return 1;
        }
        return n < m  -1 : 1;
    }

    vector<int> mergeSequence(vector<int> v1, vector<int> v2){
        int pos1 = 0, pos2 = 0;
        vector<int> ans;
        for (int i = 0; i < v1.size() + v2.size(); i++)
        {
            if (pos1 < v1.size() && pos2 < v2.size())
                if (v1[pos1] > v2[pos2])
                    ans.push_back(v1[pos1]), pos1++;
                else if (v1[pos1] < v2[pos2])
                    ans.push_back(v2[pos2]), pos2++;
                else
                    if (cmp(v1, v2, pos1, pos2) < 0)
                        ans.push_back(v2[pos2]), pos2++;
                    else
                        ans.push_back(v1[pos1]), pos1++;
            else 
                if (pos1 < v1.size())
                    ans.push_back(v1[pos1]), pos1++;
                else
                    ans.push_back(v2[pos2]), pos2++;
        }
        return ans;
    }

    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<int> ret;
        int n = nums1.size();
        for (int i = 0; i < k; i++)
            ret.push_back(0);
        for (int i = 0; i <= min(n, k); i++)
        {
            if (k-i > nums2.size())
                continue;
            vector<int> l1 = maxSubsequence(nums1, i);
            vector<int> l2 = maxSubsequence(nums2, k-i);
            vector<int> ans = mergeSequence(l1, l2);
            if (cmp(ret, ans, 0, 0) < 0)
                ret = ans;
        }
        return ret;
    }
};