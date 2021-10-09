/**

    ���������������ֱ��ʾ�����ķ���?numerator �ͷ�ĸ denominator���� �ַ�����ʽ����С�� ��

    ���С������Ϊѭ��С������ѭ���Ĳ������������ڡ�

    ������ڶ���𰸣�ֻ�践�� ����һ�� ��

    �������и��������룬��֤ ���ַ����ĳ���С�� 104 ��

    ��Դ�����ۣ�LeetCode��
    ���ӣ�https://leetcode-cn.com/problems/fraction-to-recurring-decimal
    ����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������

**/

class Solution {
public:

    const double eps = 1e-6;

    string fractionToDecimal(int numerator, int denominator) {
        string ret = "";
        bool minus = false;
        if (1.0L * numerator * denominator < 0L){
            minus = 1;
        }
        numerator = abs(numerator);
        denominator = abs(denominator);
        double ans = fabs(1.0 * numerator / denominator);
        vector<long long> s;
        long long start;
        bool flag = 0;
        long long integ = numerator / denominator;
        long long n = (numerator % denominator) * 10;
        if (numerator == 0)
            return "0";
        if (ans == (long long)numerator / (long long)denominator){
            if (minus)
                ret += '-';
            ret += to_string((long long)(ans));
            return ret;
        }
        while (1){
            if (n == 0){
                flag = 1;
                break;
            }
            start = n;
            if (find(s.begin(), s.end(), n) != s.end())
                break;
            s.push_back(n);
            if (n >= denominator)
                n %= denominator;
            n *= 10;
        }
        if (flag){
            if (minus)
                ret += '-';
            ret += to_string(integ);
            ret += ".";
            for (auto i = s.begin(); i != s.end(); i++){
                ret += to_string(*i/denominator);
            }
            return ret;
        }
        if (minus)
            ret += '-';
        ret += to_string(integ);
        ret += ".";
        string cycle = "(";
        for (auto i = find(s.begin(), s.end(), start); i != s.end() ; i++){
            cycle += to_string(*i/denominator);
        }
        for (auto i = s.begin(); i != find(s.begin(), s.end(), start); i++){
            ret += to_string(*i/denominator);
        }
        cycle += ")";
        ret += cycle;
        return ret;
    }
};