/**
    多级双向链表中，除了指向下一个节点和前一个节点指针之外，它还有一个子链表指针，可能指向单独的双向链表。这些子列表也可能会有一个或多个自己的子项，依此类推，生成多级数据结构，如下面的示例所示。

    给你位于列表第一级的头节点，请你扁平化列表，使所有结点出现在单级双链表中。


    来源：力扣（LeetCode）
    链接：https://leetcode-cn.com/problems/flatten-a-multilevel-doubly-linked-list
    著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

**/

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:

    void dfs(Node* head, Node* tail){
        Node* tmp = head;
        while (tmp != nullptr){
            if (tmp->child != nullptr){
                Node* next = tmp->next;
                Node* child = tmp->child;
                tmp->child = nullptr;
                tmp->next = child;
                child->prev = tmp;
                // cout << "enter:child = " << child->val << " tail = " << next->val << endl;
                dfs(child, next);
                // cout << "out: tail = " << tail << endl;
            }
            if (tmp->next == nullptr){
                tmp->next = tail;
                if (tail != nullptr)
                    tail->prev = tmp;
                return;
            }
            tmp = tmp->next;
        }
    }

    Node* flatten(Node* head) {
        dfs(head, nullptr);
        return head;
    }
};