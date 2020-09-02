/**
 *  * Definition for singly-linked list.
 *   * struct ListNode {
 *    *     int val;
 *     *     ListNode *next;
 *      *     ListNode(int x) : val(x), next(NULL) {}
 *       * };
 *        */
typedef ListNode Node;
class Solution {
    public:
        bool hasCycle(ListNode *head) {
            if (head==NULL||head->next==NULL)
                return 0;
            Node* fast=head->next->next;
            Node* slow=head->next;
            while (fast!=slow&&fast&&fast->next)
            {
                fast=fast->next->next;
                slow=slow->next;

            }
            if (fast==NULL||fast->next==NULL)
            {
                return 0;

            }
            else
                return 1;

        }

};
*   }
