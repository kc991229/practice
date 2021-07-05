// 给定一个排序数组，你需要在 原地 删除重复出现的元素，使得每个元素只出现一次，返回移除后数组的新长度
// 不要使用额外的数组空间，你必须在 原地 修改输入数组 并在使用 O(1) 额外空间的条件下完成。

#include <iostream>
#include <string>
#include <vector>
using std::vector;
class Solution {
    public:

        int removeDuplicates(vector<int>& nums)
        {
            if (nums.size()== 0)
                return 0;
            if (nums.size() == 1)
                return 1;
            vector<int>::iterator it1=nums.begin();
            vector<int>::iterator it2=nums.begin();
            it2++;
            while (it2!=nums.end())
            {
                if (*it1 == *it2)
                {
                    nums.erase(it2);
                    it2=it1;
                    it2++;
                }
                else
                {
                    it1++,it2++;
                }
            }
            return nums.size();
        }
};
