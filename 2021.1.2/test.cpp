//给定一个二叉树，检查它是否是镜像对称的。

#include <iostream>
#include <queue>
using std::queue;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

};
bool check1(TreeNode *p, TreeNode *q) {
    if (!p && !q) return true;
    if (!p || !q) return false;
    return p->val == q->val && check1(p->left, q->right) && check1(p->right, q->left);

}

bool isSymmetric(TreeNode* root) {
    return check1(root, root);

}

bool check(TreeNode *u, TreeNode *v) 
{
    queue <TreeNode*> q;
    q.push(u); q.push(v);
    while (!q.empty()) 
    {
        u = q.front(); q.pop();
        v = q.front(); q.pop();
        if (!u && !v) continue;
        if ((!u || !v) || (u->val != v->val)) return false;

        q.push(u->left);
        q.push(v->right);

        q.push(u->right);
        q.push(v->left);

    }
    return true;

}
