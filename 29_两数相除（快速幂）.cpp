/**

    给定两个整数，被除数 dividend 和除数 divisor。将两数相除，要求不使用乘法、除法和 mod 运算符。

    返回被除数 dividend 除以除数 divisor 得到的商。

    整数除法的结果应当截去（truncate）其小数部分，例如：truncate(8.345) = 8 以及 truncate(-2.7335) = -2

    来源：力扣（LeetCode）
    链接：https://leetcode-cn.com/problems/divide-two-integers
    著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

**/

class Solution {
public:

    int div(int a, int b){
        if(a > b)return 0;
        int res = 1, step = b;
        while(a - step <= step){
            step += step;
            res += res;
        }
        return res + div(a - step, b);
    }
    int divide(int dividend, int divisor) {
        if(dividend == INT_MIN && divisor == -1)return INT_MAX;
        if(divisor == 1)return dividend;
        int flag = 0;
        if(divisor > 0)divisor = -divisor, flag ^= 1;
        if(dividend > 0)dividend = -dividend, flag ^= 1;
        return flag ? -div(dividend, divisor) : div(dividend, divisor);
    }
    /**
    int divide(int dividend, int divisor) {
        int sign = 1;
        if (1.0L * dividend * divisor < 0)
            sign = 0;
        if (dividend == INT_MIN && divisor == -1)
            return INT_MAX;
        int ans = 0;
        long long n = abs(1.0*dividend);
        long long m = abs(1.0*divisor);
        if (n < m)
            return 0;
        long long pows[32];
        int cnt[32];
        int p = 1;
        pows[0] = m;
        cnt[0] = 1;
        int pos = 0;
        for (int i = 1; i < 32; i++){
            cout << "enter" << endl;
            if (m+m > INT_MAX || m > n)
                break;
            m = m + m;
            p = p + p;
            pows[i] = m;
            cnt[i] = p;
            pos = i;
        }
        m = abs(divisor);
        if (m == 1)
            return (sign==1) ? n : -n;
        for (int i = pos; i >= 0; i--){
            cout << "enter2" << endl;
            while (n >= pows[i]){
                n -= pows[i];
                ans += cnt[i];
            }
            if (n < m)
                break;
        }
        if (!sign)
            return -ans;
        return ans;
    }
    **/
};