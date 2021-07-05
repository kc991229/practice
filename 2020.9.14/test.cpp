//合并两个有序数组
#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <algorithm>
#include <unordered_map>
using namespace std;
class Solution {
    public:
        void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
            if (n==0)
                return;
            if (m==0)
            {
                nums1=nums2;
                return;

            }
            vector<int> result;
            int i=0,j=0;
            while(i<m && j<n)
            {
                if (nums1[i]<=nums2[j])
                {
                    result.push_back(nums1[i]);
                    i++;

                }
                else
                {
                    result.push_back(nums2[j]);
                    j++;

                }

            }
            if (i!=m)
            {
                while (i!=m)
                {
                    result.push_back(nums1[i]);
                    i++;

                }

            }
            else{
                while (j!=n)
                {
                    result.push_back(nums2[j]);
                    j++;

                }

            }
            nums1=result;

        }

};
