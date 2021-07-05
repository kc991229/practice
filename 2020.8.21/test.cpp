//验证回文串

class Solution {
    public:
        bool isPalindrome(string s) {
            if (s.empty())
                return true;
            for (int k = 0; k < s.size(); k++)
            {
                if (s[k] >= 'A'&&s[k] <= 'Z')
                    s[k] += 32;

            }
            int i = 0, j = s.size() - 1;
            while (i < j)
            {
                if (!((s[i] >= 'a'&&s[i] <= 'z') || (s[i] >= '0'&&s[i] <= '9')))
                {
                    i++;
                    continue;

                }
                if (!((s[j] >= 'a'&&s[j] <= 'z') || (s[j] >= '0'&&s[j] <= '9')))
                {
                    j--;
                    continue;

                }
                if (s[i] != s[j])
                    return false;
                i++;
                j--;

            }
            return true;

        }

};
