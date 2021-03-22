#include <iostream>
#include <string>
#include <vector>
#include <ctype.h>
#include <stack>
#include <map>
using namespace std;


//逆波兰表达式求解
int evalRPN(vector<string>& tokens) {
    stack<int> st;
    int first=0,second=0;
    for (auto s : tokens)
    {
        if (isdigit(s[0]) || isdigit(s[1]))
        {
            st.push(atoi(s.c_str()));

        }
        else
        {
            char sign=s[0];
            int num=0;
            second=st.top();
            st.pop();
            first=st.top();
            st.pop();
            switch(sign)
            {
                case'+':num=first+second;st.push(num);break;
                case'-':num=first-second;st.push(num);break;
                case'*':num=first*second;st.push(num);break;
                case'/':num=first/second;st.push(num);break;

            }

        }

    }
    return st.top();
}
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
//复制带随机指针的单链表
Node* copyRandomList(Node* head) {
    if (head==NULL)
        return head;
    Node* cur1=head;
    Node newhead(0);
    Node* cur2=&newhead;
    map<Node*,Node*> mp;
    while (cur1)
    {
        Node* newnode=new Node(cur1->val);
        newnode->random=cur1->random;
        cur2->next=newnode;
        cur2=cur2->next;
        mp[cur1]=newnode;
        cur1=cur1->next;
    }
    cur1=newhead.next;
    while (cur1)
    {
        cur1->random=mp[cur1->random];
        cur1=cur1->next;
    }
    return newhead.next;
}
struct ListNode
{
    ListNode* next;
    int val;
};
//环形链表
bool hasCycle(ListNode *head) {
    if (head==NULL || head->next==NULL)
        return false;
    ListNode* fast=head->next->next;
    ListNode* slow=head;
    while (fast!=slow && fast!=NULL)
    {
        fast=fast->next;
        slow=slow->next;
        if (fast==NULL)
            return false;
        fast=fast->next;
    }
    if (fast==NULL)
        return false;
    else
        return true;
}

//相交链表
ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    ListNode* cur1=headA;
    ListNode* cur2=headB;
    int num1=0,num2=0;
    while (cur1)
    {
        num1++;
        cur1=cur1->next;
    }
    while (cur2)
    {
        num2++;
        cur2=cur2->next;
    }
    int dif=abs(num1-num2);
    cur1=headA,cur2=headB;
    if (num1>num2)
    {
        while (dif--)
        {
            cur1=cur1->next;
        }
    }
    else
    {
        while (dif--)
        {
            cur2=cur2->next;
        }
    }
    while (cur1!=cur2)
    {
        cur1=cur1->next;
        cur2=cur2->next;
    }
    return cur1;
}

//反转链表
ListNode* reverseList(ListNode* head) {
    if (head==nullptr || head->next==nullptr)
        return head;
    ListNode* cur1=nullptr;
    ListNode* cur2=head;
    while (cur2!=nullptr)
    {
        ListNode* tmp=cur2->next;
        cur2->next=cur1;
        cur1=cur2;
        cur2=tmp;
    }
    return cur1;
}
