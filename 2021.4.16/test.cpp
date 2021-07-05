#include <iostream>
#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

//删除链表中val节点
ListNode* removeElements(ListNode* head, int val) {
    ListNode newhead(0,head);
    ListNode* cur1=&newhead,*cur2=head;
    while (cur2!=nullptr){
        if (cur2->val==val){
            cur1->next=cur2->next;
            cur2=cur2->next;
        }
        else{
            cur1=cur2;
            cur2=cur2->next;
        }
    }
    return newhead.next;
}

int maxArea(vector<int>& height) {
    int l = 0, r = height.size() - 1;
    int ans = 0;
    while (l < r) {
        int area = min(height[l], height[r]) * (r - l);
        ans = max(ans, area);
        if (height[l] <= height[r]) {
            ++l;
        }
        else {
            --r;
        }
    }
    return ans;
}
