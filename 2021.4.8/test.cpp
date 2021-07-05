#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

//143重排链表
void reorderList(ListNode* head) {
    vector<ListNode*> vec;
    ListNode* cur=head;
    while (cur){
        vec.push_back(cur);
        cur=cur->next;
    }
    ListNode newhead;
    cur=&newhead;
    for (int i=0, j=vec.size()-1;i<=j;i++,j--){
        cur->next=vec[i];
        cur=cur->next;
        if (i==j)
            break;
        cur->next=vec[j];
        cur=cur->next;
    }
    cur->next=nullptr;
}
ListNode* FindMidNode(ListNode* head){
    ListNode* fast = head;
    ListNode* slow = head;
    while (fast != nullptr && fast->next != nullptr){
        fast = fast->next;
        slow = slow->next;
        if (fast)
            fast = fast->next;
    }
    return slow;
}
ListNode* reverse(ListNode* head){
    if (head == nullptr || head->next == nullptr)
        return head;
    ListNode* cur1 = nullptr;
    ListNode* cur2 = head;
    while (cur2 != nullptr){
        ListNode* tmp = cur2->next;
        cur2->next = cur1;
        cur1 = cur2;
        cur2 = tmp;
    }
    return cur1;
}
void merge(ListNode* head1, ListNode* head2){
    ListNode newhead;
    ListNode* cur = &newhead;
    while (head1 != head2 && head2 != nullptr){
        cur->next = head1;
        head1 = head1->next;
        cur = cur->next;
        cur->next = head2;
        head2 = head2->next;
        cur = cur->next;
    }
    if (head2){
        cur->next = head2;
    }
}
void reorderList1(ListNode* head) {
    ListNode* mid = FindMidNode(head);
    ListNode* newhead = reverse(mid);
    merge(head, newhead);
}

//18删除节点
ListNode* deleteNode(ListNode* head, int val) {
            ListNode newhead(0);
                    newhead.next=head;
                            ListNode* cur1=&newhead;
                                    ListNode* cur2=head;
                                    while (cur2!=NULL){
                                        if (cur2->val==val){
                                                            cur1->next=cur2->next;
                                                                            return newhead.next;
                                                                                        
                                        }
                                                    cur1=cur2;
                                                                cur2=cur2->next;
                                                                        
                                    }
                                            return newhead.next;
                                                
}
