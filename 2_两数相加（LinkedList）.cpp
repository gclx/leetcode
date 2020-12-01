/**

	��������?�ǿ� ������������ʾ�����Ǹ������������У����Ǹ��Ե�λ���ǰ���?����?�ķ�ʽ�洢�ģ��������ǵ�ÿ���ڵ�ֻ�ܴ洢?һλ?���֡�

	��������ǽ��������������������᷵��һ���µ���������ʾ���ǵĺ͡�

	�����Լ���������� 0 ֮�⣬���������������� 0?��ͷ��

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