//编写一个函数来查找字符串数组中的最长公共前缀。
//如果不存在公共前缀，返回空字符串 ""。

class Solution {
    public:
        string longestCommonPrefix(vector<string>& strs) {
            if (!strs.size()) {
                return "";

            }
            int length = strs[0].size();
            int count = strs.size();
            for (int i = 0; i < length; ++i) {
                char c = strs[0][i];
                for (int j = 1; j < count; ++j) {
                    if (i == strs[j].size() || strs[j][i] != c) {
                        return strs[0].substr(0, i);

                    }

                }

            }
            return strs[0];

        }



};
