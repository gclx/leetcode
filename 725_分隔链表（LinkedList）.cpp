/**

    ����һ��ͷ���Ϊ head �ĵ������һ������ k ���������һ���㷨������ָ�Ϊ k �������Ĳ��֡�

    ÿ���ֵĳ���Ӧ�þ����ܵ���ȣ����������ֵĳ��Ȳ�಻�ܳ��� 1 ������ܻᵼ����Щ����Ϊ null ��

    �� k ������Ӧ�ð����������г��ֵ�˳�����У���������ǰ��Ĳ��ֵĳ���Ӧ�ô��ڻ�������ں���ĳ��ȡ�

    ����һ�������� k ������ɵ����顣

    ��Դ�����ۣ�LeetCode��
    ���ӣ�https://leetcode-cn.com/problems/split-linked-list-in-parts
    ����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������

**/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        vector<ListNode*> ret;
        vector<ListNode*> pos;
        ListNode * tmp = head;
        ListNode * nul = nullptr;
        int sum = 0;
        while (tmp != nullptr){
            pos.push_back(tmp);
            tmp = tmp->next;
            sum++;
        }
        int minN = sum / k;
        int maxN = minN + 1;
        int cnt = 0;
        int index = 0;
        while (cnt*maxN+(k-cnt)*minN != sum){
            int n = maxN-1;
            ListNode * sub = pos[index];
            while (n > 0){
                sub = sub->next;
                n--;
            }
            sub->next = nullptr;
            ret.push_back(pos[index]);
            index += maxN;
            cnt++;
        }
        while (index < sum){
            int n = minN-1;
            ListNode * sub = pos[index];
            while (n > 0){
                sub = sub->next;
                n--;
            }
            sub->next = nullptr;
            ret.push_back(pos[index]);
            index += minN;
            cnt++;
        }
        while (cnt < k){
            ret.push_back(nul);
            cnt++;
        }
        return ret;
    }
};