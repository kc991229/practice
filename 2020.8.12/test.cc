#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
bool containsDuplicate(vector<int>& nums) 
{
        if (nums.size() == 0 || nums.size() == 1)
                    return false;
            std::sort(nums.begin(), nums.end());
                for (int i = 0; i<nums.size()-1; i++)
                {
                            if (nums[i] == nums[i + 1])
                                            return true;
                                
                }
                    return false;

}
int main()
{
        vector<int> v;
            v.push_back(3);
                v.push_back(1);
                    cout << containsDuplicate(v);
                        return 0;

}
