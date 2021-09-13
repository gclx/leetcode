/**

    ����һ��ֻ���������ַ����ַ������������� *��дһ����������������ַ����Ƿ�Ϊ��Ч�ַ�������Ч�ַ����������¹���

    �κ������� (��������Ӧ�������� )��
    �κ������� )��������Ӧ�������� (��
    ������ ( �����ڶ�Ӧ��������֮ǰ )��
    *���Ա���Ϊ���������� )���򵥸������� (����һ�����ַ�����
    һ�����ַ���Ҳ����Ϊ��Ч�ַ�����

    ��Դ�����ۣ�LeetCode��
    ���ӣ�https://leetcode-cn.com/problems/valid-parenthesis-string
    ����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������

**/


class Solution {
public:
    bool checkValidString(string s) {
        int l = 0, r = 0;
        for (int i = 0; i < s.size(); i++){
            if (s[i] == '(')
                l++, r++;
            else if (s[i] == ')'){
                r--;
                l = max(l-1, 0);
            }
            else{
                r++;
                l = max(l-1, 0);
            }
            if (r < 0)
                return false;
        }
        if (l <= 0)
            return true;
        else
            return false;
    }
};