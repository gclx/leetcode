/**

	给你一个字符串 s 和一个字符串数组 dictionary 作为字典，找出并返回字典中最长的字符串，该字符串可以通过删除 s 中的某些字符得到。

	如果答案不止一个，返回长度最长且字典序最小的字符串。如果答案不存在，则返回空字符串。

	 
	来源：力扣（LeetCode）
	链接：https://leetcode-cn.com/problems/longest-word-in-dictionary-through-deleting
	著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

**/


class Solution {
public:

    int check(string s, string t){
        int cnt = 0;
        int pos = 0;
        for (int i = 0; i < t.size(); i++){
            for (int j = pos; j < s.size(); j++, pos++){
                if (s[j] == t[i]){
                    cnt++;
                    pos++;
                    break;
                }
            }
            if (cnt == t.size())
                return cnt;
        }
        return 0;
    }

    string findLongestWord(string s, vector<string>& dictionary) {
        sort(dictionary.begin(), dictionary.end());
        int maxLen = 0;
        string ret;
        for (int i = 0; i < dictionary.size(); i++){
            int len = check(s, dictionary[i]);
            if (len > maxLen){
                maxLen = len;
                ret = dictionary[i];
            }
        }
        return ret;
    }
};