//实现 strStr() 函数。

class Solution {
    public:
        int strStr(string haystack, string needle) {
            if (needle.empty())
                return 0;
            int size=needle.size();
            int begin=0;
            int i=0;
            while (begin<haystack.size())
            {
                if (haystack.size()-begin<needle.size())
                    return -1;
                i=0;
                string compare=haystack.substr(begin,size);
                while ( i<compare.size() )
                {
                    if (compare[i]==needle[i])
                        i++;
                    else
                        break;

                }
                if (i==compare.size())
                    return begin;
                begin++;

            }
            return -1;

        }

};
