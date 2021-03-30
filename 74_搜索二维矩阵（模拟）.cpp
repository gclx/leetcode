/**
	编写一个高效的算法来判断?m x n?矩阵中，是否存在一个目标值。该矩阵具有如下特性：

	每行中的整数从左到右按升序排列。
	每行的第一个整数大于前一行的最后一个整数。
**/

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = matrix.size();
        int col = matrix[0].size();
        int pos = row-1;
        if (target < matrix[0][0] || target > matrix[row-1][col-1])
            return false;
        for (int i = 0; i < row-1; i++)
            if (target >= matrix[i][0] && target < matrix[i+1][0])
                pos = i;
        if (find(matrix[pos].begin(), matrix[pos].end(), target) != matrix[pos].end())
            return true;
        else
            return false;
    }
};