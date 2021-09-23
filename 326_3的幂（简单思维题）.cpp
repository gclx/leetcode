/**

	给定一个整数，写一个函数来判断它是否是 3 的幂次方。如果是，返回 true ；否则，返回 false 。

	整数 n 是 3 的幂次方需满足：存在整数 x 使得 n == 3x

	来源：力扣（LeetCode）
	链接：https://leetcode-cn.com/problems/power-of-three
	著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

**/

// 循环 | 递归
class Solution {
public:

    bool dfs(int n){
        if (n == 3)
            return true;
        if (n && n/3 == 1.0*n/3)
            return dfs(n/3);
        else
            return false;
    }

    bool isPowerOfThree(int n) {
        if (n == 1)
            return true;
        return dfs(n);
    }
};

// 数学
class Solution {
public:

    bool isPowerOfThree(int n) {
        int x = pow(3, 19);
        if (n <= 0)
            return false;
        return x % n == 0;
    }
};