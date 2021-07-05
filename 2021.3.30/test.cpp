#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

//打家劫舍
int rob(vector<int>& nums) {
    int size=nums.size();
    if (size==0)
        return 0;
    if (size==1)
        return nums[0];
    vector<int> dp(size);
    dp[0]=nums[0];
    dp[1]=max(nums[1],dp[0]);
    for (int i=2;i<size;i++){
        dp[i]=max(dp[i-1],dp[i-2]+nums[i]);
    }
    return dp[size-1];
}


//最长上升子序列
int lengthOfLIS(vector<int>& nums) {
    int size=nums.size();
    if (size==1)
        return size;
    vector<int> dp(size,0);
    for (int i=0;i<size;i++){
        dp[i]=1;
        for (int j=0;j<i;j++){
            if (nums[i]>nums[j]){
                dp[i]=max(dp[i],dp[j]+1);
            }
        }
    }
    return *max_element(dp.begin(),dp.end());
}
