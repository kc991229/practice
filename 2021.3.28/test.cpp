#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <limits.h>
using namespace std;

//寻找峰值
int findPeakElement(vector<int>& nums) { 
    if (nums.size()==1)
        return 0;
    for (int i=0;i<(int)nums.size();i++)
    {
        if ((i==0||nums[i]>nums[i-1]) && (i==(int)nums.size()-1 || nums[i]>nums[i+1]))
            return i;
    }
    return nums.size()-1;
}
int search(vector<int>& nums, int l, int r) {
    if (l == r)
        return l;
    int mid = (l + r) / 2;
    if (nums[mid] > nums[mid + 1])
        return search(nums, l, mid);
    return search(nums, mid + 1, r);
}
int findPeakElement1(vector<int>& nums) {
    return search(nums, 0, nums.size() - 1);
}

//计算右侧小于当前元素得值
class Solution {
    private:
        vector<int> c;
        vector<int> a;

        void Init(int length) {
            c.resize(length, 0);
        }

        int LowBit(int x) {
            return x & (-x);
        }

        void Update(int pos) {
            while (pos < (int)c.size()) {
                c[pos] += 1;
                pos += LowBit(pos);
            }
        }

        int Query(int pos) {
            int ret = 0;
            while (pos > 0) {
                ret += c[pos];
                pos -= LowBit(pos);
            }
            return ret;
        }

        void Discretization(vector<int>& nums) {
            a.assign(nums.begin(), nums.end());
            sort(a.begin(), a.end());
            a.erase(unique(a.begin(), a.end()), a.end());
        }

        int getId(int x) {
            return lower_bound(a.begin(), a.end(), x) - a.begin() + 1;
        }
    public:
        vector<int> countSmaller(vector<int>& nums) {
            vector<int> resultList;
            Discretization(nums);
            Init(nums.size() + 5);
            for (int i = (int)nums.size() - 1; i >= 0; --i) {
                int id = getId(nums[i]);
                resultList.push_back(Query(id - 1));
                Update(id);
            }
            reverse(resultList.begin(), resultList.end());
            return resultList;
        }
};

int dfs(const string& s, int l, int r, int k) {
    vector<int> cnt(26, 0);
    for (int i = l; i <= r; i++) {
        cnt[s[i] - 'a']++;
    }
    char split = 0;
    for (int i = 0; i < 26; i++) {
        if (cnt[i] > 0 && cnt[i] < k) {
            split = i + 'a';
            break;
        }
    }
    if (split == 0) {
        return r - l + 1;
    }
    int i = l;
    int ret = 0;
    while (i <= r) {
        while (i <= r && s[i] == split) {
            i++;
        }
        if (i > r) {
            break;
        }
        int start = i;
        while (i <= r && s[i] != split) {
            i++;
        }
        int length = dfs(s, start, i - 1, k);
        ret = max(ret, length);
    }
    return ret;
}
int longestSubstring(string s, int k) {
    int n = s.length();
    return dfs(s, 0, n - 1, k);
}

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class Solution1 {
    private:
        int maxSum = INT_MIN;

    public:
        int maxGain(TreeNode* node) {
            if (node == nullptr) {
                return 0;
            }

            // 递归计算左右子节点的最大贡献值
            // 只有在最大贡献值大于 0 时，才会选取对应子节点
            int leftGain = max(maxGain(node->left), 0);
            int rightGain = max(maxGain(node->right), 0);

            // 节点的最大路径和取决于该节点的值与该节点的左右子节点的最大贡献值
            int priceNewpath = node->val + leftGain + rightGain;

            // 更新答案
            maxSum = max(maxSum, priceNewpath);

            // 返回节点的最大贡献值
            return node->val + max(leftGain, rightGain);
        }
        int maxPathSum(TreeNode* root) {
            maxGain(root);
            return maxSum;
        }
};
