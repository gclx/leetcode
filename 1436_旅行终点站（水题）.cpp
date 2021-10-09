/**

    ����һ��������·ͼ������·ͼ�е�������·������ paths ��ʾ������ paths[i] = [cityAi, cityBi] ��ʾ����·����� cityAi ֱ��ǰ�� cityBi �������ҳ�������е��յ�վ����û���κο���ͨ���������е���·�ĳ��С�

    ��Ŀ���ݱ�֤��·ͼ���γ�һ��������ѭ������·�����ǡ��һ�������յ�վ��

    ��Դ�����ۣ�LeetCode��
    ���ӣ�https://leetcode-cn.com/problems/destination-city
    ����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������

**/

class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        vector<string> s, t;
        for (auto i : paths){
            s.push_back(i[0]);
            t.push_back(i[1]);
        }
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        int poss= 0, post = 0;
        while (1){
            //cout << s[poss] << " " << t[post] << endl;
            if (s[poss] == t[post]){
                poss++, post++;
            } else {
                if (s[poss] < t[post])
                    poss++;
                else
                    return t[post];
            }
            if (poss == s.size())
                return t[post];
        }
        return "";
    }
};