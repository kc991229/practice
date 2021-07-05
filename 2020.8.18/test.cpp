//给出一个 32 位的有符号整数，你需要将这个整数中每位上的数字进行反转

class Solution {
    public:
        int reverse(int x) {
            queue<int> st;
            int result = 0;
            int num = x;
            if (x==-2147483648)
                return 0;
            if (x < 0)
                num = -num;
            while (num)
            {
                st.push(num % 10);
                num /= 10;

            }
            while (!st.empty())
            {

                if (2147483647 / 10  < result )
                    return 0;
                else
                    result = result * 10 + st.front();
                st.pop();

            }
            if (x < 0)
                return -result;
            else
                return result;

        }

};
