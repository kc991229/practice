//两个无序链表的排序
#include <unordered_map>
#include <iostream>
#include <vector>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}

};

class Solution {
    public:
        ListNode* merge(ListNode* n1,ListNode* n2)
        {
            if (n1==nullptr)
                return n2;
            if (n2==nullptr)
                return n1;
            ListNode newhead;
            ListNode* cur=&newhead;
            while (n1 && n2)
            {
                if (n1->val > n2->val)
                {
                    cur->next=n2;
                    cur=cur->next;
                    n2=n2->next;

                }
                else
                {
                    cur->next=n1;
                    cur=cur->next;
                    n1=n1->next;

                }

            }
            if (n1)
                cur->next=n1;
            if (n2)
                cur->next=n2;
            return newhead.next;

        }
        ListNode* sortList(ListNode* head,ListNode* tail)
        {
            if (head==nullptr)
                return head;
            if (head->next==tail)
            {
                head->next=nullptr;
                return head;

            }
            ListNode* fast=head;
            ListNode* slow=head;
            while (fast!=tail)
            {
                slow=slow->next;
                fast=fast->next;
                if (fast!=tail)
                    fast=fast->next;

            }
            ListNode* mid=slow;
            return merge(sortList(head,mid),sortList(mid,tail));

        }
        ListNode* sortList(ListNode* head) {
            return sortList(head,nullptr);

        }

};
class Node {
    public:
        int val;
        Node* next;
        Node* random;

        Node(int _val) {
            val = _val;
            next = NULL;
            random = NULL;

        }

};

Node* copyRandomList(Node* head) {
    unordered_map<Node*,Node*> mp;
    Node* cur=head;
    Node newhead(1);
    Node* headptr=&newhead;
    while (cur)
    {
        Node* newnode=new Node(cur->val);
        headptr->next=newnode;
        headptr=headptr->next;
        mp[cur]=newnode;
        cur=cur->next;

    }
    cur=head;
    headptr=newhead.next;
    while (headptr)
    {
        headptr->random=mp[cur->random];
        cur=cur->next;
        headptr=headptr->next;

    }
    return newhead.next;

}
