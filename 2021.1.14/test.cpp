//寻找两数之和

class Solution {
    public:
        vector<int> twoSum(vector<int>& nums, int target) {
            vector<int> res;
            unordered_map<int,int> m;
            for (int i=0;i<nums.size();i++)
            {
                auto it=m.find(target-nums[i]);
                if (it!=m.end())
                {
                    res.push_back(i);
                    res.push_back(it->second);
                    return res;

                }
                m[nums[i]]=i;

            }
            return res;

        }

};
