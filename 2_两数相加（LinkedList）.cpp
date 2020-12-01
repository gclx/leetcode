/**

	给出两个?非空 的链表用来表示两个非负的整数。其中，它们各自的位数是按照?逆序?的方式存储的，并且它们的每个节点只能存储?一位?数字。

	如果，我们将这两个数相加起来，则会返回一个新的链表来表示它们的和。

	您可以假设除了数字 0 之外，这两个数都不会以 0?开头。

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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* ans = new ListNode();
        ListNode* ret = ans;
        ListNode* last = ans;
        bool flag = 0;
        while (l1 != nullptr && l2 != nullptr)
        {
            last = ans;
            int n = l1->val + l2->val + flag;
            if (n < 10)
                ans->val = n, flag = 0;
            else
                ans->val = n % 10, flag = 1;
            l1 = l1->next;
            l2 = l2->next;
            ans->next = new ListNode();
            ans = ans->next;
        }

        while (l1 != nullptr)
        {
            last = ans;
            int n = l1->val + flag;
            if (n < 10)
                ans-> val = n, flag = 0;
            else
                ans->val = n%10, flag = 1;
            l1 = l1->next;
            ans->next = new ListNode();
            ans = ans->next;
        }

        while (l2 != nullptr)
        {
            last = ans;
            int n = l2->val + flag;
            if (n < 10)
                ans-> val = n, flag = 0;
            else
                ans->val = n%10, flag = 1;
            l2 = l2->next;
            ans->next = new ListNode();
            ans = ans->next;
        }
        
        if (flag)
            ans->val = 1;
        else
            last->next = nullptr;
        return ret;
    }
};