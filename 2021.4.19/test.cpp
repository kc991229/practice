#include <iostream>
#include <vector>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
//中间节点
ListNode* middleNode(ListNode* head) {
    ListNode *cur1=head;
    ListNode *cur2=head;
    while (cur2!=NULL && cur2->next!=NULL){
        cur1=cur1->next;
        cur2=cur2->next;
        if (cur2)
            cur2=cur2->next;
    }
    return cur1;
}

//链表相交
ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    if (headA==NULL || headB==NULL)
        return NULL;
    ListNode *cur1=headA,*cur2=headB;
    int countA=0,countB=0;
    while (cur1->next){
        countA++;
        cur1=cur1->next;
    }
    while (cur2->next){
        countB++;
        cur2=cur2->next;
    }
    if (cur1!=cur2)
        return NULL;
    cur1=headA,cur2=headB;
    countA++,countB++;
    if (countA>countB){
        int dif=countA-countB;
        while (dif--){
            cur1=cur1->next;
        }
        while (cur1!=cur2){
            cur1=cur1->next;
            cur2=cur2->next;
        }
        return cur1;
    }
    else{
        int dif=countB-countA;
        while (dif--){
            cur2=cur2->next;
        }
        while (cur1!=cur2){
            cur1=cur1->next;
            cur2=cur2->next;
        }
        return cur1;
    }
}

void dfs(vector<int>& candidates, int target, vector<vector<int>>& ans, vector<int>& combine, int idx) {
    if (idx == (int)candidates.size()) {
        return;
    }
    if (target == 0) {
        ans.emplace_back(combine);
        return;
    }
    // 直接跳过
    dfs(candidates, target, ans, combine, idx + 1);
    // 选择当前数
    if (target - candidates[idx] >= 0) {
        combine.emplace_back(candidates[idx]);
        dfs(candidates, target - candidates[idx], ans, combine, idx);
        combine.pop_back();
    }
}
vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    vector<vector<int>> ans;
    vector<int> combine;
    dfs(candidates, target, ans, combine, 0);
    return ans;
}

