#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
//寻找两个数组中的中位数
class Solution {
    public:
        double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
            float ret;
            for (auto v :nums2)
            {
                nums1.push_back(v);

            }
            sort(nums1.begin(),nums1.end());
            if (nums1.size()%2==0)
            {
                ret=nums1[nums1.size()/2-1]+nums1[nums1.size()/2];
                return ret/2;

            }
            else
            {
                ret=nums1[nums1.size()/2];
                return ret;

            }

        }

};
//最大连续子数组的和
class Solution1 {
    public:
        int maxSubArray(vector<int>& nums) {
            if (nums.empty())
                return 0;
            vector<int> dp(nums);
            int i=0;
            int maxnums=dp[0];
            for ( i=1;i<nums.size();i++ )
            {
                dp[i]=max(dp[i],dp[i]+dp[i-1]);
                maxnums=max(maxnums,dp[i]);

            }
            return maxnums;

        }

};
