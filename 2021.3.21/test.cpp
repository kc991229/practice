#include <iostream>
#include <vector>
#include <deque>
#include <numeric>
using namespace std;

//求滑动窗口的最大值集合
vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    int n = nums.size();
    int begin = 1 - k;
    int end = 0;
    deque<int> que;
    vector<int> res;
    if (n<k)
        return{};
    while (end<n)
    {
        while (!que.empty() && (nums[que.back()] <= nums[end]))
        {
            que.pop_back();
        }
        que.push_back(end);
        while (que.front() < begin)
            que.pop_front();
        if (begin >= 0)
        {
            res.push_back(nums[que.front()]);
        }
        begin++, end++;
    }
    return res;
}

//设计计算器
int calculate(string s) {
    int num=0;
    char sign='+';
    int n = s.length();
    vector<int> st;
    for (int i=0;i<(int)s.size();i++)
    {
        if (isdigit(s[i]))
        {
            num=num*10+int(s[i]-'0');
        }
        if ((!isdigit(s[i]) && s[i]!=' ')|| i==n-1)
        {
            switch(sign)
            {
                case'+':
                    st.push_back(num);break;
                case'-':
                    st.push_back(-num);break;
                case'*':
                    st.back()*=num;break;
                case'/':
                    st.back()/=num;break;
            }
            sign=s[i];
            num=0;
        }

    }
    return accumulate(st.begin(),st.end(),0);
}
