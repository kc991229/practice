#include <iostream>
#include <vector>
#include <string>
#include <stack>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

//奇偶链表
ListNode* oddEvenList(ListNode* head) {
    if (head==nullptr || head->next==nullptr)
    {
        return head;

    }
    ListNode head1;
    ListNode head2;
    bool num=true;
    ListNode* cur1=&head1;
    ListNode* cur2=&head2;
    while (head!=nullptr)
    {
        if (num)
        {
            cur1->next=head;
            head=head->next;
            cur1=cur1->next;
            num=!num;
        }
        else
        {
            num=!num;
            cur2->next=head;
            cur2=cur2->next;
            head=head->next;
        }
    }
    cur1->next=head2.next;
    cur2->next=nullptr;
    return head1.next;
}

//删除链表中的节点
void deleteNode(ListNode* node) {
    ListNode* cur1=node;
    ListNode* cur2=node->next;
    while (cur2!=NULL)
    {
        if (cur2->next==NULL)
        {
            break;
        }
        swap(cur1->val,cur2->val);
        cur1=cur2;
        cur2=cur2->next;
    }
    swap(cur1->val,cur2->val);
    cur1->next=NULL;
}

//回文链表
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
bool isPalindrome(ListNode* head) {
    if (head==nullptr || head->next==nullptr)
        return true;
    ListNode* fast=head;
    ListNode* slow=head;
    while ( fast && fast->next!=nullptr )
    {
        fast=fast->next;
        slow=slow->next;
        fast=fast->next;
    }
    ListNode* mid=slow;
    ListNode* newhead=reverseList(mid);
    while (head && newhead && newhead!=head)
    {
        if (head->val!=newhead->val)
            return false;
        head=head->next;
        newhead=newhead->next;
    }
    return true;
}

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}

};
//二叉树的倒数第k小节点
int kthSmallest(TreeNode* root, int k) {
    stack<TreeNode*> st;
    TreeNode* cur=root;
    while (!st.empty() || cur)
    {
        while (cur)
        {
            st.push(cur);
            cur=cur->left;
        }
        cur=st.top();
        k--;
        if (k==0)
            return cur->val;
        st.pop();
        cur=cur->right;
    }
    return 0;
}

//二叉树的最近公共祖先
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if (root == nullptr || p == root || q == root) {
        return root;
    }
    TreeNode* l = lowestCommonAncestor(root->left, p, q);
    TreeNode* r = lowestCommonAncestor(root->right, p, q);

    return l == nullptr ? r : (r == nullptr ? l : root);
}
