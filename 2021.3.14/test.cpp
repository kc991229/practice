//数数问题
#include <iostream>
#include <vector>
#include <map>
using namespace std;
vector<int> GetNum(vector<int> vec, int size, int k)
{
    vector<int> res(size - k + 1);
    vector<vector<int>> dp(size, vector<int>(size));
    map<int, int> mp;
    for (int i = 0; i < size-1; i++)
    {
        mp.clear();
        dp[i][i] = vec[i];
        mp[vec[i]]++;
        for (int j = i+1; j < size; j++)
        {
            mp[vec[j]]++;
            if (mp[dp[i][j - 1]] != mp[vec[j]])
                dp[i][j] = max(mp[dp[i][j - 1]], mp[vec[j]]);
            else
                dp[i][j] = min(dp[i][j - 1], vec[j]);

        }

    }
    for (int i = 0, j=k-1; i < size-k+1; i++,j++)
    {
        res[i] = dp[i][j];

    }
    return res;
}

//寻找数字

vector<int> FindNums(string s)
{
    vector<string> vec;
    string tmp = "";
    for (auto str : s)
    {
        if (str >= '0' && str <= '9')
        {
            tmp += str;

        }
        else
        {
            if (tmp != "")
            {
                vec.push_back(tmp);
                tmp = "";

            }

        }

    }
    if (tmp != "")
        vec.push_back(tmp);
    vector<int> res;
    for (auto st : vec)
    {
        res.push_back(atoi(st.c_str()));

    }
    return res;

}
