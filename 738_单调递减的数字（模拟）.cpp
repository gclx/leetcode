/**

	����һ���Ǹ�����N���ҳ�С�ڻ����N������������ͬʱ���������Ҫ���������λ���ϵ������ǵ���������

	�����ҽ���ÿ������λ���ϵ�����x��y����x <= yʱ�����ǳ���������ǵ��������ġ���

**/

class Solution {
public:
    int monotoneIncreasingDigits(int N) {
        vector<int> v;
        int flag = 0;
        while (N)
        {
            int after = N % 10 + flag;
            int before = N / 10 % 10;
            if (after < before)
                flag = -1, v.push_back(-1);
            else
                flag = 0, v.push_back(after);
            N /= 10;
        }
        for (int i = v.size()-1; i >= 0; i--)
            if (v[i] == -1)
            {
                for (int j = 0; j <= i; j++)
                    v[j] = 9;
                break;
            }
        int ans = 0;
        for (int i = v.size()-1; i >= 0; i--)
            ans = ans * 10 + v[i];
        return ans;
    }
};