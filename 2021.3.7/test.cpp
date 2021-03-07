//给定一个非空字符串 s 和一个包含非空单词的列表 wordDict，判定 s 是否可以被空格拆分为一个或多个在字典中出现的单词。
//说明：
//拆分时可以重复使用字典中的单词。
//你可以假设字典中没有重复的单词。
//示例 1：
//输入: s = "leetcode", wordDict = ["leet", "code"]
//输出: true
//解释: 返回 true 因为 "leetcode" 可以被拆分成 "leet code"。
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <unordered_set>
using namespace std;
bool judge_break(string s,vector<string> dit)
{
    vector<bool> dp(s.size()+1);
    unordered_set<string> myset;
    for (auto str: dit)
    {
        myset.insert(str);
    }
    dp[0]=true;
    int i=0,j=0;
    for (i=1;i<dp.size()+1;i++)
    {
        for (j=0;j<i;j++)
        {
            if (dp[j]&&myset.find(s.substr(j,i-j))!=myset.end())
            {
                dp[i]=true;
                break;
            }
        }
    }
    return dp[s.size()];
}

//三角形最小路径和
//给定一个三角形 triangle ，找出自顶向下的最小路径和。
//每一步只能移动到下一行中相邻的结点上。相邻的结点 在这里指的是 下标 与 上一层结点下标 相同或者等于 上一层结点下标 + 1 的两个结点。也就是说，如果正位于当前行的下标 i ，那么下一步可以移动到下一行的下标 i 或 i + 1 。
//示例 1：
//输入：triangle = [[2],[3,4],[6,5,7],[4,1,8,3]]
//输出：11
//解释：如下面简图所示：
//   2    
//  3 4
// 6 5 7
//4 1 8 3
//自顶向下的最小路径和为 11（即，2 + 3 + 5 + 1 = 11）
int triangle(vector<vector<int>> tri)
{
    int n=tri.size();
    int i=0,j=0;
    vector<vector<int>> dp(n,vector<int>(n));
    dp[0][0]=tri[0][0];
    for ( i=1;i<n;i++)
    {
        dp[i][0]=dp[i-1][0]+tri[i][0];
        for ( j=1;j<i;j++)
        {
            dp[i][j]=min(tri[i][j],tri[i-1][j])+tri[i][j];
        }
        dp[i][i]=tri[i-1][j-1]+dp[i][j];
    }
    return *min_element(dp[n-1].begin(),dp[n-1].end());
}


