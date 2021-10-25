/**
 * 
 *  编写一个高效的算法来搜索 m x n 矩阵 matrix 中的一个目标值 target 。该矩阵具有以下特性：
    每行的元素从左到右升序排列。
    每列的元素从上到下升序排列。

    来源：力扣（LeetCode）
    链接：https://leetcode-cn.com/problems/search-a-2d-matrix-ii
    著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 * 
 **/

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        for (int i = 0; i < m; i++){
            if (target < matrix[i][0] || target > matrix[i][n-1])
                continue;
            int pos = lower_bound(matrix[i].begin(), matrix[i].end(), target) - matrix[i].begin();
            if (matrix[i][pos] == target)
                return true;
        }
        return false;
    }
};