// offer_2021.7.6.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>
#include <unordered_map>
#include <stack>
using namespace std;

//剑指offer3：数组中重复的数字
//思路1：哈希表，时间复杂度O(N)，空间复杂度O(N)
//思路2：对应值归位法，即从0下标开始，将其交换至对应位置，已经在对应位置则不交换，出现相同值返回即可
int findRepeatNumber(vector<int>& nums) {
#if 0
  unordered_map<int, bool> count_mp;
  for (auto n : nums) {
    if (count_mp[n] == true) {
      return n;
    }
    count_mp[n] = true;
  }
  return -1;
#endif
  for (unsigned int i = 0; i < nums.size(); i++) {
    while (nums[i] != i) {
      if (nums[nums[i]] == nums[i]) {
        return nums[i];
      } else {
        swap(nums[i], nums[nums[i]]);
      }
    }
  }
  return -1;
}

//剑指offer4：二维数组的查找
//思路：画图分析，发现突破口为右上角的数字，它是行中最大的列中最小的，用它开始对比，若比原数大则y--；
//若比原数小则x++。找到返回true，若x或y任意越界，则返回false
bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
  if (matrix.size() == 0)
    return false;
  unsigned int x = 0,y = matrix[0].size() - 1;
  while (x < matrix.size() && y >= 0) {
    if (target == matrix[x][y]) {
      return true;
    } else if (target > matrix[x][y]) {
      x++;
    } else {
      y--;
    }
  }
  return false;
}

//剑指offer5：替换空格
//分析：内存覆盖问题。若从前往后遍历必然引发内存覆盖问题；从后往前遍历并移位虽可实现但效率低
//题解：遍历得到空格的个数，替换后的大小为：原长度+空格个数*3。
//定义两个指针，一个指向尾，一个指向替换后应在的位置，挨个拷贝并前移一位；遇到空格则替换为%20并前移3位
string ReplaceSpace(string s) {
  int space_count = 0;
  for (auto str : s) {
    if (str == ' ') {
      space_count++;
    }
  }
  int first = s.size() - 1;
  s.resize(s.size() + space_count * 2);
  int second = s.size() - 1;
  while (first != second) {
    if (s[first] == ' ') {
      first--;
      s[second--] = '0';
      s[second--] = '2';
      s[second--] = '%';
    } else {
      s[second--] = s[first--];
    }
  }
  return s;
}

//剑指offer6：从尾到头打印一个链表
//考察：链表、循环、栈的理解
//思路：利用栈先进后出的特性，将节点入栈，再挨个记录
struct ListNode {
  ListNode* next;
  int val;
  ListNode() {
    next = nullptr;
    val = 0;
  }
};
vector<int> ReversePrint(ListNode* head) {
  stack<ListNode*> node_stack;
  ListNode* tmp = head;
  while (tmp != nullptr) {
    node_stack.push(tmp);
    tmp = tmp->next;
  }
  vector<int> res;
  while (!node_stack.empty()) {
    res.push_back(node_stack.top()->val);
    node_stack.pop();
  }
  return res;
}

//剑指offer7：重建二叉树
struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
}

//剑指offer9：用两个栈实现队列
//思路：两个栈模拟法。栈的特性为先进先后，队列特性为先进先出，因此可以使用连个栈，一个做入队列操作-
//一个做出队列操作
class CQueue {
public:
  CQueue() {
  }

  void appendTail(int value) {
    st1.push(value);
  }

  int deleteHead() {
    if (!st2.empty()) {
      int tmp = st2.top();
      st2.pop();
      return tmp;
    } else {
      if (st1.empty()) {
        return -1;
      }
      while (!st1.empty()) {
        st2.push(st1.top());
        st1.pop();
      }
      int tmp = st2.top();
      st2.pop();
      return tmp;
    }
  }
private:
  stack<int> st1;
  stack<int> st2;
};

//剑指offer10：斐波那契数列和青蛙跳台
class Solution {
public:
  int fib(int n) {
    if (n < 2) return n;
    int first = 0;
    int two = 1;
    for (int i = 2; i <= n; i++) {
      two = first + two;
      first = two - first;
      two = (two % 1000000007);
    }
    return two;
  }
  int numWays(int n) {
    if (n <= 2) {
      return n;
    }
    int tmp1 = 1, tmp2 = 2;
    for (int i = 3; i <= n; i++) {
      tmp2 = tmp1 + tmp2;
      tmp1 = tmp2 - tmp1;
    }
    return tmp2;
  }
};

//剑指offer11：旋转数组的最小数字
int minArray(vector<int>& numbers) {

}

//剑指offer15：二进制中1的个数
//重点在于负数的处理，若仅仅是用右移做，由于负数的最高最需要置1，会导致死循环
//解法：定义一个tmp=1，与n相与并左移，解果为1则count++
int hammingWeight(uint32_t n) {
  int count = 0;
  uint32_t num = 1;
  while (n <= num) {
    if (n & num) {
      count++;
    }
    num = num << 1;
  }
  return count;
}


int main()
{
  string str = "We are happy.";
  cout << ReplaceSpace(str);
}


