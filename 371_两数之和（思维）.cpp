/**

    给你两个整数 a 和 b ，不使用 运算符 + 和 - ???????，计算并返回两整数之和。

**/

class Solution {
public:
    int getSum(int a, int b) {
        while (b){
            unsigned int tmp = (unsigned int)(a & b) << 1;
            a = a ^ b;
            b = tmp;
        }
        return a;
    }
};