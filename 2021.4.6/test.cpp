#include <iostream>
#include <vector>
#include <string>
#include <stack>

using namespace std;

class Solution {
    private:
        const uint32_t M1 = 0x55555555; // 01010101010101010101010101010101
        const uint32_t M2 = 0x33333333; // 00110011001100110011001100110011
        const uint32_t M4 = 0x0f0f0f0f; // 00001111000011110000111100001111
        const uint32_t M8 = 0x00ff00ff; // 00000000111111110000000011111111

    public:
        uint32_t reverseBits(uint32_t n) {
            n = n >> 1 & M1 | (n & M1) << 1;
            n = n >> 2 & M2 | (n & M2) << 2;
            n = n >> 4 & M4 | (n & M4) << 4;
            n = n >> 8 & M8 | (n & M8) << 8;
            return n >> 16 | n << 16;
        }
};

//两数相加，链表形式
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution1 {
    public:
        ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
            ListNode newhead(0);
            ListNode* head=&newhead;
            stack<int> st1,st2;
            while (l1!=NULL){
                st1.push(l1->val);
                l1=l1->next;
            }
            while (l2!=NULL){
                st2.push(l2->val);
                l2=l2->next;
            }
            int sign=0;
            int tmp=0;
            while (!st1.empty() && !st2.empty()){
                tmp=st1.top()+st2.top()+sign;
                st1.pop();st2.pop();
                sign=tmp/10;
                ListNode* newnode=new ListNode(tmp%10);
                newnode->next=head->next;
                head->next=newnode;
            }
            if (!st1.empty()){
                while (!st1.empty()){
                    tmp=st1.top()+sign;
                    st1.pop();
                    sign=tmp/10;
                    ListNode* newnode=new ListNode(tmp%10);
                    newnode->next=head->next;
                    head->next=newnode;
                }
            }
            if (!st2.empty()){
                while (!st2.empty()){
                    tmp=st2.top()+sign;
                    st2.pop();
                    sign=tmp/10;
                    ListNode* newnode=new ListNode(tmp%10);
                    newnode->next=head->next;
                    head->next=newnode;
                }
            }
            if (sign==1){
                ListNode* newnode=new ListNode(sign);
                newnode->next=head->next;
                head->next=newnode;
            }
            return newhead.next;
        }
};

