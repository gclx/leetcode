/**

������ n̨����ϴ�»�����ͬһ���ϡ���ʼ��ʱ��ÿ̨ϴ�»��ڿ�����һ�������·���Ҳ�����ǿյġ�

��ÿһ�������У������ѡ������ m (1 <= m <= n) ̨ϴ�»������ͬʱ��ÿ̨ϴ�»���һ���·��͵����ڵ�һ̨ϴ�»���

����һ����������machines �����������ÿ̨ϴ�»��е������������������������ϴ�»���ʣ�µ������������ȵ� ���ٵĲ������� ���������ʹÿ̨ϴ�»��������������ȣ��򷵻� -1 ��

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/super-washing-machines
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������

**/

class Solution {
public:
    int findMinMoves(vector<int>& machines) {
        int sum = accumulate(machines.begin(), machines.end(), 0);
        int n = machines.size();
        if (sum % n)
            return -1;
        int avg = sum / n;
        int ans = 0, ret = 0;
        for (auto i : machines){
            int cnt = i-avg;
            ans += cnt;
            ret = max(max(abs(ans), cnt), ret);
        }
        return ret;
    }
};