/** 

	����һ���ַ���sequence������ַ��� word�����ظ�k���γɵ��ַ�����sequence��һ�����ַ�������ô����word �� �ظ�ֵΪ k ������ word�� ����ظ�ֵ�ǵ���word��sequence�������ظ�ֵ�����word����sequence���Ӵ�����ô�ظ�ֵkΪ 0 ��

	����һ���ַ��� sequence�� word�����㷵�� ����ظ�ֵk ��

**/

class Solution {
public:
    int maxRepeating(string sequence, string word) {
        string s = "";
        for (int i = 0; ; i++)
        {
            s += word;
            if (sequence.find(s) == s.npos)
                return i;
        }
    }
};