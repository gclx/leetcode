/**

    ������������ a �� b ����ʹ�� ����� + �� - ???????�����㲢����������֮�͡�

**/

class Solution {
public:
    int getSum(int a, int b) {
        while (b){
            unsigned int tmp = (unsigned int)(a & b) << 1;
            a = a ^ b;
            b = tmp;
        }
        return a;
    }
};