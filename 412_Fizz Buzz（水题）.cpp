/**

    给你一个整数 n ，找出从 1 到 n 各个整数的 Fizz Buzz 表示，并用字符串数组 answer（下标从 1 开始）返回结果，其中：

    answer[i] == "FizzBuzz" 如果 i 同时是 3 和 5 的倍数。
    answer[i] == "Fizz" 如果 i 是 3 的倍数。
    answer[i] == "Buzz" 如果 i 是 5 的倍数。
    answer[i] == i 如果上述条件全不满足。

    来源：力扣（LeetCode）
    链接：https://leetcode-cn.com/problems/fizz-buzz
    著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

**/

class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> v;
        for (int i = 1; i <= n; i++){
            if (i % 15 == 0) v.push_back("FizzBuzz");
            else if (i % 5 == 0) v.push_back("Buzz");
            else if (i % 3 == 0) v.push_back("Fizz");
            else v.push_back(to_string(i));
        }
        return v;
    }
};