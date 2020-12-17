/**

	����һ����������prices�����е�i��Ԫ�ش����˵�i��Ĺ�Ʊ�۸� ���Ǹ�����fee �����˽��׹�Ʊ���������á�
	��������޴ε���ɽ��ף�������ÿ�ʽ��׶���Ҫ�������ѡ�������Ѿ�������һ����Ʊ����������֮ǰ��Ͳ����ټ��������Ʊ�ˡ�

	���ػ����������ֵ��

	ע�⣺�����һ�ʽ���ָ������в�������Ʊ���������̣�ÿ�ʽ�����ֻ��ҪΪ֧��һ�������ѡ�

**/

class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        const int maxn = 5e4+7;
        int dp[maxn][2];
        dp[0][0] = 0;
        dp[0][1] = -prices[0];
        for (int i = 1; i < prices.size(); i++){
            dp[i][0] = max(dp[i-1][0], dp[i-1][1] + prices[i]-fee);
            dp[i][1] = max(dp[i-1][1], dp[i-1][0] - prices[i]);
        }
        return dp[prices.size()-1][0];
    }
};