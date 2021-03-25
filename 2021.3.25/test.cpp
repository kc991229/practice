#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
using namespace std;

//设计一个常数时间插入、删除、返回随机数的容器
class RandomizedSet {
    private:
        unordered_map<int,int> mp;
        vector<int> vec;
    public:
        /** Initialize your data structure here. */
        RandomizedSet() {
        }
        /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
        bool insert(int val) {
            if (mp.count(val))
            {
                return false;
            }
            else
            {
                vec.push_back(val);
                mp[val]=vec.size()-1;
                return true;
            }
        }

        /** Removes a value from the set. Returns true if the set contained the specified element. */
        bool remove(int val) {
            if (mp.count(val))
            {
                int pos=mp[val];
                mp.erase(val);
                if (pos!=(int)vec.size()-1)
                {
                    swap(vec[pos],vec[vec.size()-1]);
                    mp[vec[pos]]=pos;
                }
                vec.pop_back();
                return true;
            }
            else{
                return false;
            }
        }

        /** Get a random element from the set. */
        int getRandom() {
            int num=rand()%vec.size();
            return vec[num];
        }
};

//最大数
string largestNumber(vector<int>& nums) {
    sort(nums.begin(),nums.end(),[](const int& num1,const int& num2){
            return to_string(num1) + to_string(num2) > to_string(num2) + to_string(num1);
            });
    string ans="";
    for (auto n : nums)
    {
        ans+=to_string(n);
        if (ans[0]=='0')
            return ans;
    }
    return ans;
}

//寻找重复数
int findDuplicate(vector<int>& nums) {
    unordered_map<int,int> mp;
    for (auto n : nums)
    {
        if (mp.count(n))
            return n;
        else
        {
            mp[n]++;
        }
    }
    return 0;
}

//只出现一次的数字
int singleNumber(vector<int>& nums) {
    int num=0;
    for (auto n : nums)
    {
        num^=n;
    }
    return num;
}

