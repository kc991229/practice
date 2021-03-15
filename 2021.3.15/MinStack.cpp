#include <iostream>
#include <stack>
using namespace std;

class MinStack
{
    public:
        MinStack() {
        }

        void push(int x) {
            st.push(x);
            if (minst.empty())
                minst.push(x);
            else
            {
                if (x<minst.top())
                    st.push(x);
            }
        }

        void pop() {
            int x=st.top();
            st.pop();
            if (minst.top()==x)
                minst.pop();
        }

        int top() {
            return st.top();
        }

        int getMin() {
            return minst.top();
        }
    private:
        stack<int> st;
        stack<int> minst;
};
