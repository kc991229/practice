#include <iostream>
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
        ListNode* rotateRight(ListNode* head, int k) {
            if (head==NULL)
                return NULL;
            if (k==0)
                return head;
            int count=1;
            ListNode* cur=head;
            while (cur->next!=NULL)
            {
                count++;
                cur=cur->next;

            }
            if (k>count)
                k=k%count;
            cur->next=head;
            ListNode* fast=head;
            ListNode* slow=head;
            while (k--)
                fast=fast->next;
            while (fast!=cur)
            {
                fast=fast->next;
                slow=slow->next;

            }
            ListNode* newhead=slow->next;
            slow->next=NULL;
            return newhead;

        }

};
*   }
