//第一个出错的版本

// The API isBadVersion is defined for you.
bool isBadVersion(int version);

class Solution {
    public:
        int firstBadVersion(int n) {
            int left=1,right=n;
            while (left<right)
            {
                int mid = left + (right - left) / 2;
                if (isBadVersion(mid)==true)
                {
                    right=mid;
                }
                else
                {
                    left=mid+1;
                }
            }
            return left;
        }
};
