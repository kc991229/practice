//求二叉树的最大深度

int Max(int left,int right)
{
    if (left > right)
        return left;
    else
        return right;

}
int maxDepth(struct TreeNode* root){
    if (root == NULL)
        return 0;
    return 1+Max(maxDepth(root->left),maxDepth(root->right));

}
