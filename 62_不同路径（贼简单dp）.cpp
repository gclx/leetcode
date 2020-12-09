/**

	一个机器人位于一个 m x n网格的左上角 （起始点在下图中标记为 “Start” ）。
	机器人每次只能向下或者向右移动一步。机器人试图达到网格的右下角（在下图中标记为 “Finish” ）。

	问总共有多少条不同的路径？


**/

class Solution {
public:
    int uniquePaths(int m, int n) {
        const int maxn = 111;
        int dp[maxn][maxn];
        dp[1][1] = 1;
        for (int i = 1; i <= m; i++)
            for (int j = 1; j <= n; j++)
                dp[i][j] = (i==1 && j==1) ? 1 : dp[i-1][j] + dp[i][j-1];
        return dp[m][n];
    }
};