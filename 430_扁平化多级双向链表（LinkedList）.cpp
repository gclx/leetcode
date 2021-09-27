/**
    �༶˫�������У�����ָ����һ���ڵ��ǰһ���ڵ�ָ��֮�⣬������һ��������ָ�룬����ָ�򵥶���˫��������Щ���б�Ҳ���ܻ���һ�������Լ�������������ƣ����ɶ༶���ݽṹ���������ʾ����ʾ��

    ����λ���б��һ����ͷ�ڵ㣬�����ƽ���б�ʹ���н������ڵ���˫�����С�


    ��Դ�����ۣ�LeetCode��
    ���ӣ�https://leetcode-cn.com/problems/flatten-a-multilevel-doubly-linked-list
    ����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������

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