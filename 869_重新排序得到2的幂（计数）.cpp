/**
 * 
    给定正整数 N ，我们按任何顺序（包括原始顺序）将数字重新排序，注意其前导数字不能为零。

    如果我们可以通过上述方式得到 2 的幂，返回 true；否则，返回 false。

    来源：力扣（LeetCode）
    链接：https://leetcode-cn.com/problems/reordered-power-of-2
    著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

**/

class Solution {
public:
    bool reorderedPowerOf2(int n) {

        vector<vector<int>> v;
        for (int i = 0; i < 32; i++){
            vector<int> tmp(10);
            long x = (long long)pow(2, i);
            string s = to_string(x);
            for (auto ch : s)
                tmp[ch-'0']++;
            v.push_back(tmp);
        }
        vector<int> tmp(10);
        string s = to_string(n);
        for (auto ch : s)
            tmp[ch-'0']++;
        for (auto i : v){
            for (int j = 0; j < 10; j++){
                if (tmp[j] != i[j])
                    break;
                if (j == 9)
                    return true;
            }
        }
        return false;
    }
};