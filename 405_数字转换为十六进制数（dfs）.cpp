/**

    ����һ����������дһ���㷨�������ת��Ϊʮ�������������ڸ�����������ͨ��ʹ��?��������?������

    ע��:

    ʮ��������������ĸ(a-f)��������Сд��
    ʮ�������ַ����в��ܰ��������ǰ���㡣���Ҫת������Ϊ0����ô�Ե����ַ�'0'����ʾ���������������ʮ�������ַ����еĵ�һ���ַ���������0�ַ���?
    ��������ȷ����32λ�з���������Χ�ڡ�
    ����ʹ���κ��ɿ��ṩ�Ľ�����ֱ��ת�����ʽ��Ϊʮ�����Ƶķ�����

    ��Դ�����ۣ�LeetCode��
    ���ӣ�https://leetcode-cn.com/problems/convert-a-number-to-hexadecimal
    ����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������

**/

class Solution {
public:

    string ans;

    void dfs(uint n){
        if (n == 0)
            return;
        int mod = n % 16;
        //cout << mod << endl;
        if (mod >= 10)
            ans += mod+'a'-10;
        else
            ans += mod+'0';
        dfs(n/16);
    }

    string toHex(int num) {
        if (num == 0)
            return "0";
        if (num < 0)
            dfs(UINT_MAX-abs(num+1));
        else
            dfs(num);
        reverse(ans.begin(), ans.end());
        return ans;
    }
};