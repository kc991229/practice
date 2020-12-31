/**
 *  * Definition for singly-linked list.
 *   * struct ListNode {
 *    *     int val;
 *     *     ListNode *next;
 *      *     ListNode() : val(0), next(nullptr) {}
 *       *     ListNode(int x) : val(x), next(nullptr) {}
 *        *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 *         * };
 *          */
class Solution {
    public:
        ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
            if (l1==NULL)
                return l2;
            if (l2==NULL)
                return l1;

            ListNode* n1=l1;
            ListNode* n2=l2;
            ListNode* n3=NULL;
            ListNode* cur=NULL;
            ListNode* head=NULL;

            if (n1->val >= n2->val)
            {
                cur=n2->next;
                n3=n2;
                n2->next=n1;
                n2=cur;

            }
            else
            {
                n3=n1;
                n1=n1->next;

            }
            head=n3;

            while (n1!=NULL && n2!=NULL)
            {
                if ((n2->val>=n3->val) && (n2->val<=n1->val))
                {
                    cur=n2->next;

                    n3->next=n2;
                    n2->next=n1;
                    n3=n3->next;

                    n2=cur;

                }
                else
                {
                    n3=n1;
                    n1=n1->next;

                }

            }

            if (n2!=NULL)
            {
                n3->next=n2;

            }
            return head;

        }

};
*   }
