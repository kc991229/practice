#include <iostream>
#include <vector>
#include <unordered_map>
#include <deque>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

//合并链表
ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
    ListNode head(0,list1);
    ListNode* cur=list1;
    while (b--){
        cur=cur->next;
    }
    ListNode* second=cur->next;
    cur=&head;
    while (a--){
        cur=cur->next;
    }
    ListNode* first=cur;
    first->next=list2;
    cur=list2;
    while (cur->next!=nullptr){
        cur=cur->next;
    }
    cur->next=second;
    return head.next;
}

//数组中的重复元素
int findRepeatNumber(vector<int>& nums) {
    unordered_map<int,int> mp;
    for (auto n : nums){
        mp[n]++;
        if (mp[n]>1)
            return n;
    }
    return -1;
}
int main()
{
}
