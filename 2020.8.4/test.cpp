//给定一个由 整数 组成的 非空 数组所表示的非负整数，在该数的基础上加一。
//最高位数字存放在数组的首位， 数组中每个元素只存储单个数字。
//你可以假设除了整数 0 之外，这个整数不会以零开头。
#include <iostream>
#include <vector>
using namespace std;

class Solution {
    public:
        vector<int> plusOne(vector<int>& digits) 
        {
            int len=digits.size();
            for(int i=len-1;i>=0;i--)
            {
                if(digits[i]==9) 
                    digits[i]=0;
                else
                { 
                    digits[i]++;
                    return digits;

                }

            }
            digits.push_back(0);
            digits[0]=1;
            return digits;

        }

};
