//爬楼梯
#include <iostream>
class Solution {
    public:
        int climbStairs(int n) {
            int p=0,q=0,j=1;
            for (int i=0;i<n;i++)
            {
                p=q,q=j,j=p+q;

            }
            return j;

        }

};
