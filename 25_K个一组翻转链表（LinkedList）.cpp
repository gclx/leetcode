/**

	����һ������ÿk���ڵ�һ����з�ת�����㷵�ط�ת�������

	k��һ��������������ֵС�ڻ��������ĳ��ȡ�

	����ڵ���������k������������ô�뽫���ʣ��Ľڵ㱣��ԭ��˳��

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

    ListNode* reverseList(ListNode* start, ListNode* end) {
        ListNode* cur = start;
        ListNode* prev = nullptr;
        while (cur != end){
            ListNode* tmp = cur->next;
            cur->next = prev;
            prev = cur;
            cur = tmp;
        }
        return prev;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        if (head == nullptr || head->next == nullptr)
            return head;
        ListNode* start = head;
        ListNode* end = head;
        int cnt = k;
        while (cnt--){
            if (end == nullptr)
                return head;
            end = end->next;
        }
        ListNode* newHead = reverseList(start, end);
        start->next = reverseKGroup(end, k);
        return newHead;
    }
};