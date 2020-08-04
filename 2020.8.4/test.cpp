//给定一个数组 nums，编写一个函数将所有 0 移动到数组的末尾，同时保持非零元素的相对顺序。

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
    public:
        void moveZeroes(vector<int>& nums) 
        {
            if (nums.size() == 0)
                return;
            int p1 = 0, p2 = 0;
            while (p1 < nums.size())
            {
                if (nums[p1] == 0)
                {
                    for (; p2 < nums.size();p2++)
                    {
                        if (nums[p2] != 0)
                            break;

                    }
                    if (p2 == nums.size())
                        return;
                    std::swap(nums[p1], nums[p2]);

                }
                p1++;
                if (p1>p2)
                    p2 = p1 + 1;

            }

        }

};
