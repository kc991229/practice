#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
    public:
        //寻找数组中乘积最大的子数组
        int maxProduct(vector<int>& nums) 
        {
            int maxF = nums[0], minF = nums[0], ans = nums[0];
            for (int i = 1; i < (int)nums.size(); ++i) 
            {
                int mx = maxF, mn = minF;
                maxF = max(mx * nums[i], max(nums[i], mn * nums[i]));
                minF = min(mn * nums[i], min(nums[i], mx * nums[i]));
                ans = max(maxF, ans);

            }
            return ans;
        }

        //旋转数组
        void rotate_help(int *left,int *right)
        {
            while (left<right)
            {
                *left^=*right;
                *right^=*left;
                *left^=*right;
                left++;
                right--;

            }

        }
        void rotate(int* nums, int numsSize, int k){
            if (nums==NULL||numsSize==1)
            {
                return;

            }
            k=k%numsSize;
            rotate_help(nums,nums+numsSize-k-1);
            rotate_help(nums+numsSize-k,nums+numsSize-1);
            rotate_help(nums,nums+numsSize-1);

        }

};
