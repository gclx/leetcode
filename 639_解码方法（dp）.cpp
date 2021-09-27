/**

	一条包含字母 A-Z 的消息通过以下的方式进行了编码：

	'A' -> 1
	'B' -> 2
	...
	'Z' -> 26
	要 解码 一条已编码的消息，所有的数字都必须分组，然后按原来的编码方案反向映射回字母（可能存在多种方式）。例如，"11106" 可以映射为：

	"AAJF" 对应分组 (1 1 10 6)
	"KJF" 对应分组 (11 10 6)
	注意，像 (1 11 06) 这样的分组是无效的，因为 "06" 不可以映射为 'F' ，因为 "6" 与 "06" 不同。

	除了 上面描述的数字字母映射方案，编码消息中可能包含 '*' 字符，可以表示从 '1' 到 '9' 的任一数字（不包括 '0'）。例如，编码字符串 "1*" 可以表示 "11"、"12"、"13"、"14"、"15"、"16"、"17"、"18" 或 "19" 中的任意一条消息。对 "1*" 进行解码，相当于解码该字符串可以表示的任何编码消息。

	给你一个字符串 s ，由数字和 '*' 字符组成，返回 解码 该字符串的方法 数目 。

	由于答案数目可能非常大，返回对 109 + 7 取余 的结果。

	来源：力扣（LeetCode）
	链接：https://leetcode-cn.com/problems/decode-ways-ii
	著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

**/

class Solution {
public:
    const int mod = 1e9+7;
    int numDecodings(string s) {
        long long dp[3] {0};
        long long two = 1, sum = 1;
        for (auto i : s){
            if (i == '*'){
                two = dp[1]*9 + dp[2]*6;
                dp[1] = dp[2] = sum;
                dp[0] = sum * 7;
            } else {
                two = dp[1] + (i < '7') * dp[2];
                dp[1] = (i == '1') ? sum : 0;
                dp[2] = (i == '2') ? sum : 0;
                dp[0] = (i > '2') ? sum : 0;
                if (i == '0')   dp[0] = 0;
            }
            sum = (dp[0]+dp[1]+dp[2]+two) % mod;
        }
        return sum;
    }
};