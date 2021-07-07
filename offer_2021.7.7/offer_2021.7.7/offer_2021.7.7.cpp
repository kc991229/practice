
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

//剑指offer11：旋转数组的最小数字
/*
题解：数组为排序数组旋转得来，则有特征：
1、最小值为分界线，两边均为递增序列
2、最右边的值一定比最小值左边的大且比最小值右边的小
以此建立二分查找模型，最后的值若比中间值大，证明最小值应在该中间值的左边；最后值比中间值小，最小值再右边
特殊情况：
数组为空
存在相同元素时，可能出现中间值和最后的值相同，则令最后边的坐标--
*/
int minArray(vector<int>& numbers) {
  if (numbers.size() == 0) {
    throw new exception("Invalid parameters");
  }

  int index1 = 0, index2 = numbers.size() - 1, mid = 0;
  while (index1 < index2) {
    mid = index1 + (index2 - index1) / 2;
    if (numbers[index2] > numbers[mid]) {
      index2 = mid;
    } else if (numbers[index2] < numbers[mid]) {
      index1 = mid + 1;
    } else {
      index2--;
    }
  }
  return numbers[index1];
}

/*
* 二叉树的前中后序遍历，递归与非递归形式
*/
struct BinaryTreeNode {
  BinaryTreeNode* left;
  BinaryTreeNode* right;
  int val;
  BinaryTreeNode() {
    left = nullptr;
    right = nullptr;
    val = 0;
  }
};
class BinaryTreeTraversal {
public:
  //preorder、middle 、postorder
void BinaryPerorder(vector<int>& preorder, BinaryTreeNode* root) {
  if (root == nullptr) {
    return;
  }
  preorder.push_back(root->val);
  BinaryPerorder(preorder, root->left);
  BinaryPerorder(preorder, root->right);
}

void BinaryPerorder(vector<int>& preorder, BinaryTreeNode* root) {
  stack<BinaryTreeNode*> st;
  while (!st.empty() || root) {
    while (root) {
      preorder.push_back(root->val);
      st.push(root);
      root = root->left;
    }
    root = st.top();
    st.pop();
    root = root->right;
  }
}

void BinaryMiddle(vector<int>& middle, BinaryTreeNode* root) {
  if (root == nullptr) {
    return;
  }
  BinaryMiddle(middle, root->left);
  middle.push_back(root->val);
  BinaryMiddle(middle, root->right);
}

void BinaryMiddle(vector<int>& middle, BinaryTreeNode* root) {
  stack<BinaryTreeNode*> st;
  while (!st.empty() || root) {
    while (root) {
      st.push(root);
      root = root->left;
    }
    root = st.top();
    st.pop();
    middle.push_back(root->val);
    root = root->right;
  }
}

void BinaryPostorder(vector<int>& postorder, BinaryTreeNode* root) {
  if (root == nullptr) {
    return;
  }
  BinaryPostorder(postorder, root->left);
  BinaryPostorder(postorder, root->right);
  postorder.push_back(root->val);
}

void BinaryPostorder(vector<int>& postorder, BinaryTreeNode* root) {
  stack<BinaryTreeNode*> st;
  BinaryTreeNode* prev = nullptr;
  while (!st.empty() || root) {
    while (root) {
      st.push(root);
      root = root->left;
    }
    root = st.top();
    if (root->right == nullptr ||root->right==prev) {
      postorder.push_back(root->val);
      prev = root;
      st.pop();
      root = nullptr;
    } else {
      root = root->right;
    }
  }
}
private:
};

int main()
{
    std::cout << "Hello World!\n";
}


