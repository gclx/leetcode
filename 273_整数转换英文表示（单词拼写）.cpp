/**

    将非负整数 num 转换为其对应的英文表示。

**/

class Solution {
public:
    string numberToWords(int num) {
        string s[10] = {"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine"};
        string s2[10] = {"", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
        string s3[10] = {"Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
        int n1 = num % 1000;
        int n2 = (num/1000)%1000;
        int n3 = (num/1000000)%1000;
        int n4 = num/1000000000;
        string ans = "";
        bool flag = false;
        bool skip = false;
        if (num == 0){
            return "Zero";
        }
        if (n4){
            ans += s[n4];
            ans += " Billion";
            flag = true;
        }
        if (n3){
            skip = false;
            int tmp = n3 / 100;
            if (tmp){
                if (flag)
                    ans += " ";
                ans += s[tmp];
                ans += " Hundred";
                flag = true;
            }
            tmp = n3 / 10 % 10;
            if (tmp == 1){
                int tmp2 = n3 % 100;
                if (flag)
                    ans += " ";
                ans += s3[tmp2-10];
                ans += " Million";
                flag = true;
                skip = true;
            }
            if (tmp > 1){
                if (flag)
                    ans += " ";
                ans += s2[tmp];
                flag = true;
            }
            if (!skip){
                tmp = n3 % 10;
                if (tmp){
                    if (flag)
                        ans += " ";
                    ans += s[tmp];
                }
                ans += " Million";
                flag = true;
            }
        }
        if (n2){
            skip = false;
            int tmp = n2 / 100;
            if (tmp){
                if (flag)
                    ans += " ";
                ans += s[tmp];
                ans += " Hundred";
                flag = true;
            }
            tmp = n2 / 10 % 10;
            if (tmp == 1){
                int tmp2 = n2 % 100;
                if (flag)
                    ans += " ";
                ans += s3[tmp2-10];
                ans += " Thousand";
                flag = true;
                skip = true;
            }
            if (tmp > 1){
                if (flag)
                    ans += " ";
                ans += s2[tmp];
                flag = true;
            }
            if (!skip){
                tmp = n2 % 10;
                if (tmp){
                    if (flag)
                        ans += " ";
                    ans += s[tmp];
                }
                ans += " Thousand";
                flag = true;
            }
        }
        if (n1){
            skip = false;
            int tmp = n1 / 100;
            if (tmp){
                if (flag)
                    ans += " ";
                ans += s[tmp];
                ans += " Hundred";
                flag = true;
            }
            tmp = n1 / 10 % 10;
            if (tmp == 1){
                int tmp2 = n1 % 100;
                if (flag)
                    ans += " ";
                ans += s3[tmp2-10];
                flag = true;
                skip = true;
            }
            if (tmp > 1){
                if (flag)
                    ans += " ";
                ans += s2[tmp];
                flag = true;
            }
            if (!skip){
                tmp = n1 % 10;
                if (tmp){
                    if (flag)
                        ans += " ";
                    ans += s[tmp];
                    flag = true;
                }
            }
        }
        return ans;
    }
};