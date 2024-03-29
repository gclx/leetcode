/**

    所有 DNA 都由一系列缩写为 'A'，'C'，'G' 和 'T' 的核苷酸组成，例如："ACGAATTCCG"。在研究 DNA 时，识别 DNA 中的重复序列有时会对研究非常有帮助。

    编写一个函数来找出所有目标子串，目标子串的长度为 10，且在 DNA 字符串 s 中出现次数超过一次。

    来源：力扣（LeetCode）
    链接：https://leetcode-cn.com/problems/repeated-dna-sequences
    著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

**/

class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string> ans;
        map<string, int> m;
        for (int i = 0; i <= int(s.size())-10; i++){
            string str = s.substr(i, 10);
            m[str]++;
            if (m[str] == 2)
                ans.push_back(str);
        }
        return ans;
    }
};