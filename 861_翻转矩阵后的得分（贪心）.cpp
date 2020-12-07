/**

	��һ����ά����A ����ÿ��Ԫ�ص�ֵΪ0��1��
	�ƶ���ָѡ����һ�л��У���ת�����л����е�ÿһ��ֵ�������� 0 ������Ϊ 1�������� 1 ������Ϊ 0��
	����������������ƶ��󣬽��þ����ÿһ�ж����ն������������ͣ�����ĵ÷־�����Щ���ֵ��ܺ͡�

	���ؾ����ܸߵķ�����


**/

class Solution {
public:

    void flip(vector<vector<int>>& v, bool isRow, int index){
        if (isRow)
            for (int j = 0; j < v[index].size(); j++)
                v[index][j] = !v[index][j];
        else
            for (int i = 0; i < v.size(); i++)
                v[i][index] = !v[i][index];
    }

    int matrixScore(vector<vector<int>>& A) {
        vector<vector<int>> v = A;
        for (int i = 0; i < v.size(); i++)
            if (v[i][0] == 0)
                flip(v, true, i);
        for (int j = 1; j < v[0].size(); j++)
        {
            int cnt = 0;
            for (int i = 0; i < v.size(); i++)
                if (v[i][j] == 0)
                    cnt++;
            if (cnt > v.size()/2)
                flip(v, false, j);
        }

        int ans1 = 0;
        for (int i = 0; i < v.size(); i++)
            for (int j = 0; j < v[i].size(); j++)
                ans1 += v[i][j] * pow(2, (v[i].size())-j-1);
        v = A;
        flip(v, false, 0);
        for (int i = 0; i < v.size(); i++)
            if (v[i][0] == 0)
                flip(v, true, i);
        for (int j = 1; j < v[0].size(); j++)
        {
            int cnt = 0;
            for (int i = 0; i < v.size(); i++)
                if (v[i][j] == 0)
                    cnt++;
            if (cnt > v.size()/2)
                flip(v, false, j);
        }

        int ans2 = 0;
        for (int i = 0; i < v.size(); i++)
            for (int j = 0; j < v[i].size(); j++)
                ans2 += v[i][j] * pow(2, (v[i].size())-j-1);

        return max(ans1, ans2);
    }
};