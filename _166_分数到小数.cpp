/**

    给定两个整数，分别表示分数的分子?numerator 和分母 denominator，以 字符串形式返回小数 。

    如果小数部分为循环小数，则将循环的部分括在括号内。

    如果存在多个答案，只需返回 任意一个 。

    对于所有给定的输入，保证 答案字符串的长度小于 104 。

    来源：力扣（LeetCode）
    链接：https://leetcode-cn.com/problems/fraction-to-recurring-decimal
    著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

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