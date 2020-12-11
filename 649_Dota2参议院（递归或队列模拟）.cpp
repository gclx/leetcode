/**

	Dota2 ����������������Ӫ��Radiant(���)��Dire(ҹ��)

	Dota2 ����Ժ���������ɵĲ���Ա��ɡ����ڲ���Ժϣ����һ�� Dota2 ��Ϸ��ĸı�����������������һ��������Ϊ���̵�ͶƱ���С���ÿһ���У�ÿһλ����Ա��������ʹ����Ȩ���е�һ�

	1����ֹһ������Ա��Ȩ����

		����Ա��������һλ����Ա����һ�ֺ����ļ�����ɥʧ���е�Ȩ����

	2������ʤ����

		�������Ա������Ȩ��ͶƱ�Ĳ���Ա����ͬһ����Ӫ�ģ�����������ʤ������������Ϸ�е��йر仯��

	

	����һ���ַ�������ÿ������Ա����Ӫ����ĸ ��R�� �� ��D�� �ֱ������Radiant����ԣ���Dire��ҹ�ʣ���Ȼ������� n ������Ա�������ַ����Ĵ�С����n��

	����Ϊ�����Ĺ��̴Ӹ���˳��ĵ�һ������Ա��ʼ�����һ������Ա��������һ���̽�������ͶƱ����������ʧȥȨ���Ĳ���Ա���ڹ����б�������

	����ÿһλ����Ա���㹻��������Ϊ�Լ�������������õĲ��ԣ�����ҪԤ����һ�����ջ�����ʤ������ Dota2 ��Ϸ�о����ı䡣���Ӧ����Radiant��Dire��


**/


class Solution {
public:

    int check(string s){
        int rn = 0, dn = 0;
        for (int i = 0; i < s.size(); i++)
            if (s[i] == 'R')
                rn++;
            else
                dn++;
        if (rn >= 2*dn)
            return 1;
        if (dn >= 2*rn)
            return -1;
        return 0;
    }

    string predictPartyVictory(string senate) {
        cout << senate << endl;
        int f;
        if (f = check(senate))
            return (f == 1) ? "Radiant" : "Dire";
        string s = "";
        int rn = 0, dn = 0;
        for (int i = 0; i < senate.size(); i++)
            if (senate[i] == 'R')
            {
                if (dn <= 0)
                    s += 'R', rn++;
                else
                    dn--;
            }
            else
            {
                if (rn <= 0)
                    s += 'D', dn++;
                else
                    rn--;
            }
        if (dn > 0)
            for (int i = 0; i < dn; i++)
                s += 'D';
        if (rn > 0)
            for (int i = 0; i < rn; i++)
                s += 'R';
        return predictPartyVictory(s);
    }
};