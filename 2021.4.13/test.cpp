#include <iostream>
using namespace std;

struct ListNode{
    ListNode* next;
    int val;
    ListNode(int _val,ListNode* _next){
        val=_val;
        next=_next;
    }
};
ListNode *detectCycle(ListNode *head) {
    if (head==NULL)
        return NULL;
    ListNode *fast=head,*slow=head;
    do{
        fast=fast->next;
        slow=slow->next;
        if (fast)
            fast=fast->next;
    }while (fast && fast!=slow);
    if (fast==NULL){
        return NULL;
    }
    ListNode* cur=head;
    while (slow!=cur){
        slow=slow->next;
        cur=cur->next;
    }
    return slow;
}

pair<ListNode*, ListNode*> myReverse(ListNode* head, ListNode* tail) {
    ListNode* prev = tail->next;
    ListNode* p = head;
    while (prev != tail) {
        ListNode* nex = p->next;
        p->next = prev;
        prev = p;
        p = nex;

    }
    return {tail, head};

}

ListNode* reverseKGroup(ListNode* head, int k) {
    ListNode* hair = new ListNode(0,head);
    hair->next = head;
    ListNode* pre = hair;
    while (head) {
        ListNode* tail = pre;
        for (int i = 0; i < k; ++i) {
            tail = tail->next;
            if (!tail) {
                return hair->next;
            }
        }
        ListNode* nex = tail->next;
        pair<ListNode*, ListNode*> result = myReverse(head, tail);
        head = result.first;
        tail = result.second;
        pre->next = head;
        tail->next = nex;
        pre = tail;
        head = tail->next;
    }
    return hair->next;
}


