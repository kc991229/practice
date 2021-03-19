#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
    public:
        //旋转数组
        void reverse(vector<int>& nums,int begin,int end)
        {
            while (begin<end)
            {
                swap(nums[begin],nums[end]);
                begin++;
                end--;
            }

        }
        void rotate(vector<int>& nums, int k) {
            k=k%nums.size();
            reverse(nums,0,nums.size()-1);
            reverse(nums,0,k-1);
            reverse(nums,k,nums.size()-1);
        }

        //判断是否存在重复元素
        bool containsDuplicate(vector<int>& nums) {
            unordered_map<int,int> mp;
            for (auto n : nums)
            {
                if (mp.count(n))
                    return true;
                mp[n]++;

            }
            return false;
        }

        //移动0
        void moveZeroes(vector<int>& nums) {
            int n=nums.size(),left=0,right=0;
            while (right<n)
            {
                if (nums[right])
                {
                    swap(nums[left],nums[right]);
                    left++;

                }
                right++;
            }
        }
};
