/**
 *  * Definition for singly-linked list.
 *   * struct ListNode {
 *    *     int val;
 *     *     ListNode *next;
 *      *     ListNode(int x) : val(x), next(NULL) {}
 *       * };
 *       **/

class Solution {
    public:
        bool isPalindrome(ListNode* head) {
            if (head == NULL)
            {
                return 1;

            }
            if (head->next == NULL)
                return 1;

            if (head->next->next == NULL)
            {
                if (head->val == head->next->val)
                    return 1;
                else
                    return 0;

            }

            ListNode* n1 = head;
            ListNode* n2 = head;
            while (n2 != NULL && n2->next != NULL)
            {
                n1 = n1->next;
                n2 = n2->next;
                n2 = n2->next;

            }
            n2 = head;

            ListNode* a1 = n1;
            ListNode* a2 = a1->next;
            ListNode* a3 = a2->next;
            a1->next = NULL;
            while (a2 != NULL)
            {
                a2->next = a1;
                a1 = a2;
                a2 = a3;
                if (a3 != NULL)
                    a3 = a3->next;

            }

            n1 = a1;
            a1 = a2 = a3 = NULL;
            while (n1 != NULL&&n2 != NULL)  
            {
                if (n1->val != n2->val)
                    return 0;
                n1 = n1->next;
                n2 = n2->next;

            }
            return 1;

        }

};
*   }
