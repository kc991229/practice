//翻转单链表
/**
 *  * Definition for singly-linked list.
 *   * struct ListNode {
 *    *     int val;
 *     *     ListNode *next;
 *      *     ListNode(int x) : val(x), next(NULL) {}
 *       * };
 *        */
class Solution {
    public:
        ListNode* reverseList(ListNode* head) {
            if ((head == NULL) || ((head)->next == NULL))
                return head;
            ListNode* n1 = (head);
            ListNode* n2 = (head)->next;
            ListNode* n3 = n2->next;
            n1->next = NULL;
            while (n2 != NULL)
            {
                n2->next = n1;
                n1 = n2;
                n2 = n3;
                if (n3 != NULL)//要考虑最后两个的情况
                    n3 = n3->next;

            }
            return n1;

        }

};
*   }
