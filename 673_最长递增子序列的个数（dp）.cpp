/**

	给定一个未排序的整数数组，找到最长递增子序列的个数。

**/

class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int dp[2001] {0};
        int cnt[2001] {0};
        int maxlen = 1;
        int ans = 0;
        for (int i = 0; i < nums.size(); i++){
            dp[i] = 1;
            cnt[i] = 1;
            for (int j = 0; j < i; j++){
                if (nums[i] > nums[j]){
                    if (dp[j]+1 > dp[i]){
                        dp[i] = dp[j]+1;
                        cnt[i] = cnt[j];
                    }
                    else if (dp[j]+1 == dp[i])
                        cnt[i] = cnt[i] + cnt[j];
                }
            }
            if (dp[i] > maxlen){
                ans = cnt[i];
                maxlen = dp[i];
            }
            else if (dp[i] == maxlen){
                ans += cnt[i];
            }
        }
        return ans;
    }
};