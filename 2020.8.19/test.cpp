class Solution {
    public:
        int firstUniqChar(string s) {
            int arr[26]={0};
            int size=s.size();
            for (int i=0;i<size;i++)
            {
                arr[s[i]-'a']++;

            }
            for (int j=0;j<size;j++)
            {
                if (arr[s[j]-'a']==1)
                    return j;

            }
            return -1;

        }

};
