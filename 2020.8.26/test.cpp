//请编写一个函数，使其可以删除某个链表中给定的（非末尾）节点。传入函数的唯一参数为 要被删除的节点 。

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
        void deleteNode(ListNode* node) 
        {
            ListNode* _cur = node;
            ListNode* _next = _cur->next;
            while (_next ->next != NULL)
            {
                swap(_cur->val, _next->val);
                _cur = _cur->next;
                _next = _next->next;

            }
            swap(_cur->val, _next->val);
            _cur->next = NULL;

        }

};
*   }
