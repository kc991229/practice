//给定两个数组，编写一个函数来计算它们的交集。

class Solution {
    public:
        vector<int> intersect(vector<int>& nums1, vector<int>& nums2) 
        {
            std::sort(nums1.begin(),nums1.end());
            std::sort(nums2.begin(),nums2.end());
            int num1=0,num2=0;
            vector<int> result;
            while (num1<nums1.size() && num2< nums2.size())
            {
                if (nums1[num1] == nums2[num2])
                {
                    result.push_back(nums1[num1]);
                    num1++;
                    num2++;

                }
                else
                {
                    if (nums1[num1]> nums2[num2])
                        num2++;
                    else
                        num1++;

                }

            }
            return result;

        }

};
