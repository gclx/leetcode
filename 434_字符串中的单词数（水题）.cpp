/**

    ͳ���ַ����еĵ��ʸ���������ĵ���ָ���������Ĳ��ǿո���ַ���

    ��ע�⣬����Լٶ��ַ����ﲻ�����κβ��ɴ�ӡ���ַ���

**/

class Solution {
public:
    int countSegments(string s) {
        int ans = 0;
        bool flag = 1;
        for (int i = 0; i < s.size(); i++){
            if (s[i] == ' ')
                flag = 1;
            else
                if (flag){
                    ans++;
                    flag = 0;
                }
        }
        return ans;
    }
};