/**

    给你一个头结点为 head 的单链表和一个整数 k ，请你设计一个算法将链表分隔为 k 个连续的部分。

    每部分的长度应该尽可能的相等：任意两部分的长度差距不能超过 1 。这可能会导致有些部分为 null 。

    这 k 个部分应该按照在链表中出现的顺序排列，并且排在前面的部分的长度应该大于或等于排在后面的长度。

    返回一个由上述 k 部分组成的数组。

    来源：力扣（LeetCode）
    链接：https://leetcode-cn.com/problems/split-linked-list-in-parts
    著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

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