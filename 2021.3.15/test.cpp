//整数反转
#include <iostream>
#include <limits.h>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
    public:
        int reverse(int x) {
            int rev = 0;
            while (x != 0) {
                int pop = x % 10;
                x /= 10;
                if (rev > INT_MAX/10 || (rev == INT_MAX / 10 && pop > 7)) return 0;
                if (rev < INT_MIN/10 || (rev == INT_MIN / 10 && pop < -8)) return 0;
                rev = rev * 10 + pop;
            }
            return rev;
        }
        //只出现一次的数次
        int singleNumber(vector<int>& nums) {
            int res=0;
            for (auto n : nums)
            {
                res^=n;

            }
            return res;

        }
        //判断回文数
        bool isPalindrome(int x) {
            if (x<0 || (x%10==0 && x!=0))
                return false;
            string s;
            while (x)
            {
                s.push_back(x%10);
                x/=10;

            }
            int begin=0;
            int end=s.size()-1;
            while (begin < end)
            {
                if (s[begin]!=s[end])
                    return false;
                begin++;
                end--;

            }
            return true;

        }
        //判断多数元素
        int majorityElement(vector<int>& nums) {
            sort(nums.begin(),nums.end());
            return nums[nums.size()/2];

        }
        //判断二次幂
        bool isPowerOfTwo(int n) {
            if (n<=0)
                return false;
            int m=n-1;
            return  !(m&n);

        }
};


