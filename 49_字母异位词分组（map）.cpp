/**
	给定一个字符串数组，将字母异位词组合在一起。字母异位词指字母相同，但排列不同的字符串。

**/

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string, vector<string>> m;
        for (int i = 0; i < strs.size(); i++)
        {
            string s = strs[i];
            sort(s.begin(), s.end());
            m[s].push_back(strs[i]);
        }
        vector<vector<string>> ans;
        for (auto i : m)
        {
            vector<string> v;
            for (int j = 0; j < i.second.size(); j++)
                v.push_back(i.second[j]);
            ans.push_back(v);
        }    
        return ans;
    }
};