/**

    ����һ���ַ��� s�������ɵ�����ɣ�����ǰ����һЩ�ո��ַ������������ַ��������һ�����ʵĳ��ȡ�

    ���� ��ָ������ĸ��ɡ��������κοո��ַ���������ַ�����

**/

class Solution {
public:
    int lengthOfLastWord(string s) {
        int cnt = 0;
        for (int i = s.size()-1; i >= 0; i--){
            if (s[i] == ' ' && cnt)
                return cnt;
            if (s[i] != ' ')
                cnt++;
        }
        return cnt;
    }
};