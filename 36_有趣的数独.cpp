/**

	请你判断一个 9x9 的数独是否有效。只需要 根据以下规则 ，验证已经填入的数字是否有效即可。

	数字 1-9 在每一行只能出现一次。
	数字 1-9 在每一列只能出现一次。
	数字 1-9 在每一个以粗实线分隔的 3x3 宫内只能出现一次。（请参考示例图）
	数独部分空格内已填入了数字，空白格用 '.' 表示。

	注意：

	一个有效的数独（部分已被填充）不一定是可解的。
	只需要根据以上规则，验证已经填入的数字是否有效即可。

	来源：力扣（LeetCode）
	链接：https://leetcode-cn.com/problems/valid-sudoku
	著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

**/

// 检验三遍 暴力
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int vis[3][9][10];
        memset(vis, 0, sizeof(vis));
        for (int i = 0; i < 9; i++){
            for (int j = 0; j < 9; j++){
                if (board[i][j] == '.')
                    continue;
                if (vis[0][i][board[i][j]-'0'])
                    return false;
                vis[0][i][board[i][j]-'0'] = 1;
            }
        }
        for (int i = 0; i < 9; i++){
            for (int j = 0; j < 9; j++){
                if (board[j][i] == '.')
                    continue;
                if (vis[1][i][board[j][i]-'0'])
                    return false;
                vis[1][i][board[j][i]-'0'] = 1;
            }
        }
        int pos = 0;
        for (int i = 0; i < 9; i+=3){
            for (int j = 0; j < 9; j+=3){
                for (int r = 0; r < 3; r++)
                    for (int c = 0; c < 3; c++){
                        if (board[i+r][j+c] == '.')
                            continue;
                        if (vis[2][pos][board[i+r][j+c]-'0'])
                            return false;
                        vis[2][pos][board[i+r][j+c]-'0'] = 1;
                    }
                pos++;
            }
        }
        return true;
    }
};


// 一遍检验 记录
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int row[9][9] {0};
        int col[9][9] {0};
        int sub[3][3][9] {0};
        for (int i = 0; i < 9; i++)
            for (int j = 0; j < 9; j++){
                if (board[i][j] == '.')
                    continue;
                int x = board[i][j] - '0' - 1;
                row[i][x]++;
                col[j][x]++;
                sub[i/3][j/3][x]++;
                if (row[i][x] > 1 || col[j][x] >1 || sub[i/3][j/3][x] >1)
                    return false;
            }
        return true;
    }
};