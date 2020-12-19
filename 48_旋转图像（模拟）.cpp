/**

	给定一个 n×n 的二维矩阵表示一个图像。

	将图像顺时针旋转 90 度。

	说明：
	你必须在原地旋转图像，这意味着你需要直接修改输入的二维矩阵。请不要使用另一个矩阵来旋转图像。

**/


class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int mlen = matrix.size();
        int k = mlen / 2;
        int tmp = 0;
        for (int i = 0; i < k; i++)
        {
            int len = mlen - i * 2 - 2;
            for (int j = 0; j <= len; j++)
            {
                tmp = matrix[i+j][mlen-1-i];
                // cout << tmp << endl;

                // cout << matrix[i+j][mlen-1-i] << "->" << matrix[i][i+j] << endl;
                matrix[i+j][mlen-1-i] = matrix[i][i+j];

                // cout << matrix[i][i+j] << "->" << matrix[mlen-1-i-j][i] << endl;
                matrix[i][i+j] = matrix[mlen-1-i-j][i];

                // cout << matrix[mlen-1-i-j][i] << "->" << matrix[mlen-1-i][mlen-1-i-j] << endl;
                matrix[mlen-1-i-j][i] = matrix[mlen-1-i][mlen-1-i-j];

                // cout << matrix[mlen-1-i][mlen-1-i-j] << "->" << tmp << endl;
                matrix[mlen-1-i][mlen-1-i-j] = tmp;
                
            }
        }
    }
};