/**

	����һ�������ַ��� S������ S = "123456579"�����ǿ��Խ����ֳ�쳲�����ʽ������ [123, 456, 579]��

	��ʽ�ϣ�쳲�����ʽ������һ���Ǹ������б� F�������㣺

	0 <= F[i] <= 2^31 - 1����Ҳ����˵��ÿ������������ 32 λ�з����������ͣ���
	F.length >= 3��
	�������е�0 <= i < F.length - 2������ F[i] + F[i+1] = F[i+2] ������
	���⣬��ע�⣬���ַ�����ֳ�С��ʱ��ÿ���������һ����Ҫ���㿪ͷ����������������� 0 ����

	���ش� S ��ֳ���������һ��쳲�����ʽ�����п飬������ܲ���򷵻� []��

**/

class Solution {
public:

    long long get(string s, int cnt, int pos){
        if (s[pos] == '0' && cnt != 1)
            return -1;
        long long ans = 0;
        for (int i = pos; i < pos+cnt; i++)
        {
            ans = ans * 10 + s[i] - '0';
            if (ans > INT_MAX)
                return -1;
        }
        return ans;
    }

    vector<int> splitIntoFibonacci(string S) {
        int len = S.size();
        int maxLen = len / 2;
        for (int i = 1; i <= maxLen; i++)
            for (int j = 1; j <= maxLen; j++)
            {
                vector<int> v;
                int pos = 0;
                long long ni = get(S, i, pos);
                pos += i;
                long long nj = get(S, j, pos);
                pos += j;
                if (ni < 0 || nj < 0)
                    continue;
                v.push_back(ni);
                v.push_back(nj);
                long long ans = 0;
                bool flag = false;
                while (pos < len)
                {
                    ans = ans * 10 + S[pos++] - '0';
                    if (ans == 0 && (ni+nj) != 0)
                        break;
                    if (ans > INT_MAX || ans > ni+nj)
                        break;
                    if (ans == ni+nj){
                        ni = nj;
                        nj = ans;
                        v.push_back(ans);
                        ans = 0;
                        if (pos == len)
                            flag = true;
                    }
                }
                if (flag)
                    return v;
            }
        vector<int> v;
        return v;
    }
};