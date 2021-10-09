/**

    ��һ����Կ�ַ��� S ��ֻ������ĸ�������Լ� '-'�����ۺţ������У� N �� '-' ���ַ����ֳ��� N+1 �顣

    ����һ������ K���������¸�ʽ���ַ�����ʹÿ������ǡ�ð��� K ���ַ����ر�أ���һ������������ַ���������С�ڵ��� K��������Ҫ���� 1 ���ַ�����������֮����Ҫ�� '-'�����ۺţ����������ҽ����е�Сд��ĸת��Ϊ��д��ĸ��

    �����ǿ��ַ��� S ������ K���������������Ĺ�����и�ʽ����

    ��Դ�����ۣ�LeetCode��
    ���ӣ�https://leetcode-cn.com/problems/license-key-formatting
    ����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������

**/

class Solution {
public:
    string licenseKeyFormatting(string s, int k) {
        int cnt = 0;
        for (auto i : s)
            if ( i != '-')
                cnt++;
        int fir = cnt % k;
        int pos = 0;
        string ans;
        int n = cnt / k;
        while (fir){
            if (s[pos] != '-'){
                fir--;
                ans += toupper(s[pos]);
            }
            pos++;
            if (!fir && n)
                ans += '-';
        }
        while (n--){
            int tmp = k;
            while (tmp){
                //cout << pos << endl;
                if (s[pos] != '-'){
                    tmp--;
                    ans += toupper(s[pos]);
                }
                pos++;
            }
            if (n)
                ans += '-';
        }
        return ans;
    }
};