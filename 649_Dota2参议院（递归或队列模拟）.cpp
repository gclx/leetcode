/**

	Dota2 的世界里有两个阵营：Radiant(天辉)和Dire(夜魇)

	Dota2 参议院由来自两派的参议员组成。现在参议院希望对一个 Dota2 游戏里的改变作出决定。他们以一个基于轮为过程的投票进行。在每一轮中，每一位参议员都可以行使两项权利中的一项：

	1、禁止一名参议员的权利：

		参议员可以让另一位参议员在这一轮和随后的几轮中丧失所有的权利。

	2、宣布胜利：

		如果参议员发现有权利投票的参议员都是同一个阵营的，他可以宣布胜利并决定在游戏中的有关变化。

	

	给定一个字符串代表每个参议员的阵营。字母 “R” 和 “D” 分别代表了Radiant（天辉）和Dire（夜魇）。然后，如果有 n 个参议员，给定字符串的大小将是n。

	以轮为基础的过程从给定顺序的第一个参议员开始到最后一个参议员结束。这一过程将持续到投票结束。所有失去权利的参议员将在过程中被跳过。

	假设每一位参议员都足够聪明，会为自己的政党做出最好的策略，你需要预测哪一方最终会宣布胜利并在 Dota2 游戏中决定改变。输出应该是Radiant或Dire。


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