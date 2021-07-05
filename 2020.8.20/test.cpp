
//给定两个字符串 s 和 t ，编写一个函数来判断 t 是否是 s 的字母异位词。
class Solution {
    public:
        bool isAnagram(string s, string t) {
            if (s.size()>t.size())
                swap(s,t);
            unordered_map<char, int> map;
            for (int i = 0; i < s.size(); i++)
            {
                map[s[i]]++;

            }
            for (int i = 0; i < t.size(); i++)
            {
                if (map.find(t[i]) == map.end() || map.find(t[i])->second==0)
                    return false;
                map.find(t[i])->second--;

            }
            return true;

        }

};
