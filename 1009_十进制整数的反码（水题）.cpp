/**

    每个非负整数 N 都有其二进制表示。例如， 5 可以被表示为二进制 "101"，11 可以用二进制 "1011" 表示，依此类推。注意，除 N = 0 外，任何二进制表示中都不含前导零。

    二进制的反码表示是将每个 1 改为 0 且每个 0 变为 1。例如，二进制数 "101" 的二进制反码为 "010"。

    给你一个十进制数 N，请你返回其二进制表示的反码所对应的十进制整数。

    来源：力扣（LeetCode）
    链接：https://leetcode-cn.com/problems/complement-of-base-10-integer
    著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

**/

class Solution {
public:
    int bitwiseComplement(int n) {
        int tmp;
        if (n == 0) return 1;
        for (int i = 0; i <= 31; i++)
            if ((tmp=pow(2, i)-1) >= n)
                return tmp-n;
        return 0;
    }
};