#include <iostream>
#include <vector>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


//删除链表的中间节点，参数只有该节点本身
void deleteNode(ListNode* node) {
    ListNode *cur1=node,*cur2=node->next;
    while (cur2->next!=NULL){
        swap(cur1->val,cur2->val);
        cur1=cur2,cur2=cur2->next;
    }
    swap(cur1->val,cur2->val);
    cur1->next=NULL;
}

//矩阵置零
void setZeroes(vector<vector<int>>& matrix) {
    int m = matrix.size();
    int n = matrix[0].size();
    int flag_col0 = false;
    for (int i = 0; i < m; i++) {
        if (!matrix[i][0]) {
            flag_col0 = true;
        }
        for (int j = 1; j < n; j++) {
            if (!matrix[i][j]) {
                matrix[i][0] = matrix[0][j] = 0;
            }
        }
    }
    for (int i = m - 1; i >= 0; i--) {
        for (int j = 1; j < n; j++) {
            if (!matrix[i][0] || !matrix[0][j]) {
                matrix[i][j] = 0;
            }
        }
        if (flag_col0) {
            matrix[i][0] = 0;
        }
    }
}
