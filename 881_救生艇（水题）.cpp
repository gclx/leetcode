/**
    
    ��i���˵�����Ϊpeople[i]��ÿ�Ҵ����Գ��ص��������Ϊlimit��

    ÿ�Ҵ�����ͬʱ�����ˣ�����������Щ�˵�����֮�����Ϊlimit��

    �����ص�ÿһ�����������С������(��֤ÿ���˶��ܱ�����)��

    ��Դ�����ۣ�LeetCode��
    ���ӣ�https://leetcode-cn.com/problems/boats-to-save-people
    ����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������

**/


class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end());
        int n = people.size();
        int tmp = limit, pos = 0;
        int ans = 0;
        for (int i = n-1; i >= 0; i--){
            if (pos > i)
                break;
            tmp = limit;
            ans++;
            tmp -= people[i];
            if (tmp >= people[pos]){
                pos++;
            }
        }
        return ans;
    }
};