/**
	��дһ����Ч���㷨���ж�?m x n?�����У��Ƿ����һ��Ŀ��ֵ���þ�������������ԣ�

	ÿ���е����������Ұ��������С�
	ÿ�еĵ�һ����������ǰһ�е����һ��������
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