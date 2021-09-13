/**

    һ���༶����n��ѧ�������Ϊ 0�� n - 1��ÿ��ѧ�������λش����⣬���Ϊ 0��ѧ���Ȼش�Ȼ���Ǳ��Ϊ 1��ѧ�����Դ����ƣ�ֱ�����Ϊ n - 1��ѧ����Ȼ����ʦ���ظ�������̣����´ӱ��Ϊ 0��ѧ����ʼ�ش����⡣

    ����һ������Ϊ n���±�� 0��ʼ����������chalk��һ������k��һ��ʼ�۱ʺ����ܹ���k֧�۱ʡ������Ϊi��ѧ���ش�����ʱ���������� chalk[i]֧�۱ʡ����ʣ��۱����� �ϸ�С��chalk[i]����ôѧ�� i��Ҫ ����۱ʡ�

    ���㷵����Ҫ ����۱ʵ�ѧ�� ��š�

    ��Դ�����ۣ�LeetCode��
    ���ӣ�https://leetcode-cn.com/problems/find-the-student-that-will-replace-the-chalk
    ����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������


**/


class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        long long cost = 0;
        for (int i = 0; i < chalk.size(); i++)
            cost += chalk[i];
        long long left = k - (k/cost*cost);
        for (int i = 0; i < chalk.size(); i++)
            if (left < chalk[i])
                return i;
            else
                left -= chalk[i];
        return 0;
    }
};