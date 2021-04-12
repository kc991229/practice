#include <iostream>
#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

//相交链表的第一个公共节点
ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    int count1=0,count2=0;
    ListNode* cur1=headA;
    ListNode* cur2=headB;
    while (cur1!=NULL){
        count1++;
        cur1=cur1->next;
    }
    while (cur2!=NULL){
        count2++;
        cur2=cur2->next;
    }
    cur1=headA,cur2=headB;
    if (count1>count2){
        int num=count1-count2;
        while (num--)
            cur1=cur1->next;
    }
    else{
        int num=count2-count1;
        while (num--)
            cur2=cur2->next;
    }
    while ( cur1 && cur2 ){
        if (cur1==cur2)
            return cur2;
        cur1=cur1->next;
        cur2=cur2->next;
    }
    return NULL;
}

//交换第k个和倒数第k个节点
ListNode* swapNodes(ListNode* head, int k) {
    ListNode* fast=head,*slow=head,*cur=head;
    int n=k-1;
    while (n--){
        cur=cur->next;
    }
    ListNode* first=cur;
    while (k--){
        fast=fast->next;
    }
    while (fast!=nullptr){
        fast=fast->next;
        slow=slow->next;
    }
    ListNode* second=slow;
    swap(first->val,second->val);
    return head;
}

//在排序数组中查找次数
int search(vector<int>& nums, int target) {
    int left=0,right=nums.size()-1;
    int pos=0;
    while (left <= right){
        pos=(left+right)/2;
        if (nums[pos]==target)
            break;
        if (nums[pos]>target){
            right=pos-1;
        }
        else
            left=pos+1;
    }
    if (left>right)
        return 0;
    int res=1;
    int leftn=pos-1,rightn=pos+1;
    while (leftn>=0 && nums[leftn]==target){
        res++;
        leftn--;
    }
    while (rightn <=(int) nums.size()-1 && nums[rightn]==target){
        res++;
        rightn++;
    }
    return res;
}
