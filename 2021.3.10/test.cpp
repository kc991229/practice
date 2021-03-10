//完美子串的数量
//
//如果一个字符串的子串包含了该字符串中所有出现过的字符，这样的子串我们把它称作原字符串的完美子串。比如，对于字符串
//“abcdabcabc”，子串 “abcd”，“bcda”，“abcdabcabc”……，都是它的完美子串。
//
//给定一个只包含小写英文字符的字符串，请求出它的完美子串的个数。

#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

vector<string> GetPerfectStr(string& s)
{
    int len = s.size();//记录字符串长度
    vector<string> res;//用来储存结果
    vector<vector<string>> dp(len + 1, vector<string>(len + 1));//实现动归的数组
    map<char,int> mp;//用map的去重来统计包含字符
    for (auto str : s)
    {
        mp[str]++;

    }
    string countstr = "";
    for (auto c : mp)
    {
        countstr+=c.first;

    }//到此，统计字符结束

    for (int i = 0; i < len + 1; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            dp[i][j] = countstr;

        }

    }

    for (int i = 0; i < len + 1; i++)
    {
        for (int j = 1; j < len + 1; j++)
        {
            int pos = dp[i][j - 1].find(s[i]);
            if (pos != string::npos)
            {
                dp[i][j] = dp[i][j - 1].erase(pos, 1);

            }
            else
                dp[i][j] = dp[i][j - 1];
            if (dp[i][j] == "")
            {
                res.push_back(s.substr(i, j));

            }

        }

    }
    return res;

}
