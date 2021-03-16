#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
using namespace std;

//寻找回文串
class Solution {
    private:
        vector<vector<int>> f;
        vector<vector<string>> ret;
        vector<string> ans;
        int n;

    public:
        void dfs(const string& s, int i) {
            if (i == n) {
                ret.push_back(ans);
                return;

            }
            for (int j = i; j < n; ++j) {
                if (f[i][j]) {
                    ans.push_back(s.substr(i, j - i + 1));
                    dfs(s, j + 1);
                    ans.pop_back();

                }

            }

        }

        vector<vector<string>> partition(string s) {
            n = s.size();
            f.assign(n, vector<int>(n, true));

            for (int i = n - 1; i >= 0; --i) {
                for (int j = i + 1; j < n; ++j) {
                    f[i][j] = (s[i] == s[j]) && f[i + 1][j - 1];

                }

            }

            dfs(s, 0);
            return ret;

        }
        bool wordBreak(string s, vector<string>& wordDict) {
            unordered_set<string> myset;
            for (auto str: wordDict)
            {
                myset.insert(str);

            }
            vector<bool> dp(s.size()+1);
            dp[0]=true;
            for (int i=1;i<(int)dp.size()+1;i++)
            {
                for(int j=0;j<i;j++)
                {
                    if (dp[j] && myset.find(s.substr(j,i-j))!=myset.end())
                    {
                        dp[i]=true;
                        break;

                    }

                }

            }
            return dp[s.size()];

        }
};

