/**
	
	给你两个链表list1 和list2，它们包含的元素分别为n 个和m 个。

	请你将list1中第a个节点到第b个节点删除，并将list2接在被删除节点的位置。

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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode * cur = list1;
        for (int i = 1; i < a; i++)
            cur = cur->next;
        ListNode * list1Next = cur->next;
        for (int i = 0; i < b-a+1; i++)
            list1Next = list1Next->next;
        cur->next = list2;
        while (cur->next != nullptr)
            cur = cur->next;
        cur->next = list1Next;
        return list1;
    }
};