/**

	����һ�����ַ�����?tasks ��ʾ�� CPU ��Ҫִ�е������б�����ÿ����ĸ��ʾһ�ֲ�ͬ����������������������˳��ִ�У�����ÿ�����񶼿����� 1 ����λʱ����ִ���ꡣ���κ�һ����λʱ�䣬CPU �������һ�����񣬻��ߴ��ڴ���״̬��

	Ȼ�������� ��ͬ���� ������֮������г���Ϊ���� n ����ȴʱ�䣬������������� n ����λʱ���� CPU ��ִ�в�ͬ�����񣬻����ڴ���״̬��

	����Ҫ�������������������Ҫ�� ���ʱ�� ��


**/

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int cnt[128];
        memset(cnt, 0, sizeof cnt);
        int len = tasks.size();
        int Max = 0;
        for (int i = 0; i < len; i++)
        {
            cnt[tasks[i]]++;
            Max = max(Max, cnt[tasks[i]]);
        }
        int ans = 0;
        for (int i = 0; i < 128; i++)
            if (Max == cnt[i])
                ans++;
        if ((Max-1)*(n+1)+ans >= len)
            return (Max-1)*(n+1)+ans;
        else
            return len;
    }
};