#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
int getn(int n, vector<int> vec)
{
    vector<int> dp(n);
    unordered_map<int, int> mp;
    dp[0] = 0;
    mp[vec[0]] = 0;
    for (int i = 1; i <(int) vec.size(); i++)
    {
        if (mp.count(vec[i]))
        {
            dp[i] = min(mp[vec[i]] + 1,dp[i-1]+1);
        }
        else
        {
            dp[i] = dp[i - 1] + 1;
            mp[vec[i]] = dp[i];

        }

    }
    return dp[vec.size() - 1];

}
