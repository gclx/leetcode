/**

	给你一个链表，每k个节点一组进行翻转，请你返回翻转后的链表。

	k是一个正整数，它的值小于或等于链表的长度。

	如果节点总数不是k的整数倍，那么请将最后剩余的节点保持原有顺序。

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