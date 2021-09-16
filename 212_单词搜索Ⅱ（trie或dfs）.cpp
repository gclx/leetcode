/**

	给定一个 m x n 二维字符网格 board 和一个单词（字符串）列表 words，找出所有同时在二维网格和字典中出现的单词。

	单词必须按照字母顺序，通过 相邻的单元格 内的字母构成，其中“相邻”单元格是那些水平相邻或垂直相邻的单元格。同一个单元格内的字母在一个单词中不允许被重复使用。

	 

	来源：力扣（LeetCode）
	链接：https://leetcode-cn.com/problems/word-search-ii
	著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

**/

class Solution {
public:
    vector<string> str[11];
    vector<string> ret;
    int vis[12][12];

    void dfs(string s, int x, int y, vector<vector<char>>& board){
        if (s.size() == 10)
            return;
        vis[x][y] = 1;
        s += board[x][y];
        str[s.size()].push_back(s);
        if (x != 0 && !vis[x-1][y])
            dfs(s, x-1, y, board);
        if (x != board.size()-1 && !vis[x+1][y])
            dfs(s, x+1, y, board);
        if (y != 0 && !vis[x][y-1])
            dfs(s, x, y-1, board);
        if (y != board[x].size()-1 && !vis[x][y+1])
            dfs(s, x, y+1, board);
        vis[x][y] = 0;
        s.erase(s.end()-1);
    }

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        for (int i = 0; i < board.size(); i++){
            for (int j = 0; j < board[i].size(); j++){
                string s;
                dfs(s, i, j, board);
            }
        }
        for (int i = 0; i < 11; i++)
            str[i].erase(unique(str[i].begin(), str[i].end()), str[i].end());
        for (int i = 0; i < words.size(); i++){
            int len = words[i].size();
            for (int j = 0; j < str[len].size(); j++){
                if (words[i] == str[len][j])
                    ret.push_back(words[i]);
            }
        }
        ret.erase(unique(ret.begin(), ret.end()), ret.end());
        return ret;
    }
};