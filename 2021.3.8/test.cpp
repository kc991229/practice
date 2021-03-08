//给你一个字符串 s，找到 s 中最长的回文子串。
//示例 1：
//输入：s = “babad”
//输出：“bab”
//解释：“aba” 同样是符合题意的答案。
//示例 2：
//输入：s = “cbbd”
//输出：“bb”
//示例 3：
//输入：s = “a”
//输出：“a”
//示例 4：
//输入：s = “ac”
//输出：“a”
#include <iostream>
#include <string>
#include <vector>
using namespace std;
string longestPalindrome(string s)
{
    int n=s.size();
    vector<vector<int>> dp(n,vector<int>(n));
    string ans="";
    for (int len=0;len<s.size();len++)
    {
        for (int i=0;i+len<n;i++)
        {
            int j=i+len;
            if (len==0)
            {
                dp[i][j]=1;
            }
            else if (len==1)
            {
                dp[i][j]=(s[i]==s[j]);
            }
            else
            {
                dp[i][j]=(dp[i+1][j-1]&&(s[i]==s[j]));
            }   
            if (dp[i][j]&&len>ans.size())
            {
                ans=s.substr(i,len+1);
            }
        }
    }
    return ans;
}

//给你两个单词 word1 和 word2，请你计算出将 word1 转换成 word2 所使用的最少操作数 。
//你可以对一个单词进行如下三种操作：
//插入一个字符
//删除一个字符
//替换一个字符
//示例 1：
//输入：word1 = “horse”, word2 = “ros”
//输出：3
//解释：
//horse -> rorse (将 ‘h’ 替换为 ‘r’)
//rorse -> rose (删除 ‘r’)
//rose -> ros (删除 ‘e’)
int minDistance(string word1, string word2) 
{
    int len1=word1.size();
    int len2=word2.size();
    vector<vector<int>> dp(len1+1,vector<int>(len2+1));
    //初始状态
    for (int i=0;i<len1+1;i++)
    {
        dp[i][0]=i;
    }
    for (int i=0;i<len2+1;i++)
    {
        dp[0][i]=i;
    }

    //替F[i-1][j-1]+1  插F[i][j-1]+1 删F[i-1][j]+1
    for (int i=1;i<len1+1;i++)
    {
        for (int j=1;j<len2+1;j++)
        {
            dp[i][j]=min(dp[i-1][j],dp[i][j-1])+1;
            if (word1[i-1]==word2[j-1])
            {
                dp[i][j]=min(dp[i][j],dp[i-1][j-1]);
            }
            else
            {
                dp[i][j]=min(dp[i][j],dp[i-1][j-1]+1);
            }
        }
    }
    return dp[len1][len2];
}

