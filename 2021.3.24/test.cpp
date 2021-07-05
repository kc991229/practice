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
//排序链表
ListNode* merge(ListNode* n1,ListNode* n2)
{
    if (n1==nullptr)
        return n2;
    if (n2==nullptr)
        return n1;
    ListNode newhead;
    ListNode* head=&newhead;
    while (n1 && n2)
    {
        if (n1->val > n2->val)
        {
            head->next=n2;
            n2=n2->next;
            head=head->next;
        }
        else
        {
            head->next=n1;
            n1=n1->next;
            head=head->next;
        }
    }
    if (n1)
    {
        head->next=n1;
        return newhead.next;
    }
    if (n2)
    {
        head->next=n2;
        return newhead.next;
    }
    return newhead.next;
}
ListNode* sortList(ListNode* begin,ListNode* end)
{
    if (begin==end)
    {
        return begin;
    }
    if (begin->next==end)
    {
        begin->next=nullptr;
        return begin;
    }
    ListNode* fast=begin;
    ListNode* slow=begin;
    while (fast!=nullptr && fast!=end)
    {
        fast=fast->next;
        if (fast!=end)
            fast=fast->next;
        slow=slow->next;
    }
    ListNode* mid=slow;
    return merge(sortList(begin,mid),sortList(mid,end));
}
ListNode* sortList(ListNode* head) {
    return sortList(head,nullptr);
}

//excel表格序列号
int titleToNumber(string columnTitle) {
    int res=0,count=1;
    for (int i=0;i<(int)columnTitle.size();i++)
    {
        count=columnTitle[i]-'A'+1;
        res=res*26+count;
    }
    return res;
}

//四数相加
int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
    unordered_map<int,int> mp;
    int res=0;
    for (int i=0;i<(int)A.size();i++)
    {
        for (int j=0;j<(int)B.size();j++)
        {
            mp[0-A[i]-B[j]]++;
        }
    }
    for (int i=0;i<(int)C.size();i++)
    {
        for (int j=0;j<(int)D.size();j++)
        {
            if (mp.count(C[i]+D[j]))
                res+=mp[C[i]+D[j]];
        }
    }
    return res;
}


