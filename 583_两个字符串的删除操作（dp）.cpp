/**

    给定两个单词 word1 和 word2，找到使得 word1 和 word2 相同所需的最小步数，每步可以删除任意一个字符串中的一个字符。

**/

class Solution {
public:
    int minDistance(string word1, string word2) {
        int dp[501][501];
        memset(dp, 0, sizeof dp);
        for (int i = 0; i < word1.size(); i++){
            for (int j = 0; j < word2.size(); j++){
                if (word1[i] == word2[j]){
                    dp[i+1][j+1] = max(dp[i+1][j+1], dp[i][j]+1);
                } else {
                    dp[i+1][j+1] = max(dp[i][j+1], dp[i+1][j]);
                }
            }
        }
        return word1.size() + word2.size() - 2 * dp[word1.size()][word2.size()];
    }
};