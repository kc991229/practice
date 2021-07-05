#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct ListNode{
    ListNode* next;
    int val;
    ListNode(int _val){
        next=nullptr;
        val=_val;
    }
};

//链表的插入排序
ListNode* insertionSortList(ListNode* head) {
    if (head == nullptr) {
        return head;
    }
    ListNode* dummyHead = new ListNode(0);
    dummyHead->next = head;
    ListNode* lastSorted = head;
    ListNode* curr = head->next;
    while (curr != nullptr) {
        if (lastSorted->val <= curr->val) {
            lastSorted = lastSorted->next;
        } else {
            ListNode *prev = dummyHead;
            while (prev->next->val <= curr->val) {
                prev = prev->next;
            }
            lastSorted->next = curr->next;
            curr->next = prev->next;
            prev->next = curr;
        }
        curr = lastSorted->next;
    }
    return dummyHead->next;
}

//最接近的三数之和
int threeSumClosest(vector<int>& nums, int target) {
    sort(nums.begin(), nums.end());
    int n = nums.size();
    int best = 1e7;

    auto update = [&](int cur) {
        if (abs(cur - target) < abs(best - target)) {
            best = cur;
        }
    };
    for (int i = 0; i < n; ++i) {
        if (i > 0 && nums[i] == nums[i - 1]) {
            continue;
        }
        int j = i + 1, k = n - 1;
        while (j < k) {
            int sum = nums[i] + nums[j] + nums[k];
            if (sum == target) {
                return target;
            }
            update(sum);
            if (sum > target) {
                int k0 = k - 1;
                while (j < k0 && nums[k0] == nums[k]) {
                    --k0;
                }
                k = k0;
            } else {
                int j0 = j + 1;
                while (j0 < k && nums[j0] == nums[j]) {
                    ++j0;
                }
                j = j0;
            }
        }
    }
    return best;
}
