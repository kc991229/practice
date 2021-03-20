#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <limits.h>
using namespace std;

//求数组的交集
vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
    vector<int> vec;
    int i=0,j=0;
    sort(nums1.begin(),nums1.end());
    sort(nums2.begin(),nums2.end());
    while (i<(int)nums1.size() && j<(int)nums2.size())
    {
        if (nums1[i]==nums2[j])
        {
            vec.push_back(nums1[i]);
            i++;
            j++;

        }
        else if (nums1[i]>nums2[j])
        {
            j++;

        }
        else
            i++;
    }
    return vec;
}

//递增的三元子序列
//定义一个最小small和一个mid中间值，遇到比samll小或小于替换，比mid小或等于替换
bool increasingTriplet(vector<int>& nums) {
    if (nums.size()<3)
        return false;
    int small=INT_MAX;
    int mid=INT_MAX;
    for (auto num : nums)
    {
        if (num<=small)
            small=num;
        else if (num<=mid)
            mid=num;
        else
            return true;

    }
    return false;  
}

//探索二维矩阵
bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int i=0,j=matrix[0].size()-1;
    while (i<(int)matrix.size() && j>=0)
    {
        if (matrix[i][j]==target)
            return true;
        else if (matrix[i][j]>target)
        {
            j--;
        }
        else
        {
            i++;
        }
    }
    return false;
}

//除自身以外数的乘积
vector<int> productExceptSelf(vector<int>& nums) {
    vector<int> dp(nums.size());
    dp[0]=1;
    for (int i=1;i<(int)nums.size();i++)
    {
        dp[i]=dp[i-1]*nums[i-1];

    }
    int right=1;
    for (int i=nums.size()-1;i>=0;i--)
    {
        dp[i]=dp[i]*right;
        right*=nums[i];
    }
    return dp;
}
