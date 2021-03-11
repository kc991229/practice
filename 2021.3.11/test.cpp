//翻转字符串
#include <iostream>
#include <string>
#include <stack>
#include <vector>
using namespace std;
void reverseString(vector<char>& s) {
    int head=0;
    int tail=s.size()-1;
    while (head<tail)
    {
        swap(s[head],s[tail]);
        head++;
        tail--;
    }

}

//翻转字符串中的单词
string reverseWords(string s) {
    stack<char> st;
    string res="";
    for (auto str:s)
    {
        if (str!=' ')
        {
            st.push(str);

        }
        else
        {
            while (!st.empty())
            {
                res+=st.top();
                st.pop();

            }
            res+=' ';

        }

    }
    while (!st.empty())
    {
        res+=st.top();
        st.pop();

    }
    return res;

}
