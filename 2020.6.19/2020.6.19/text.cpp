#include <iostream>
#include <string>
#include <vector>
using namespace std;
#if 0
/*
请设计一个算法完成两个超长正整数的加法。
输入：
99999999999999999999999999999999999999999999999999
1
输出：
100000000000000000000000000000000000000000000000000
*/
string arr("0123456789");
void str_sum(string& str, int end, int i)
{
	int num = 0, sum = 0;
	num = arr.find(str[end]);
	sum = num + i;
	if (sum < 10)
	{
		str[end] = arr[sum];
	}
	else
	{
		sum = sum - 10;
		str[end] = arr[sum];
		if (end != 0)
		{
			str_sum(str, end - 1, 1);
		}
		else
		{
			str[0] = '0';
			str = '1' + str;
		}
	}
}
void function()
{
	string s1, s2;
	while (cin >> s1 >> s2)
	{
		if (s1.size() < s2.size())
			swap(s1, s2);
		int i = s2.size();
		int j = 1;
		while (i--)
		{
			int num = arr.find(*(s2.end() - 1));
			str_sum(s1, s1.size() - j, num);
			s2.pop_back();
			j++;
		}
		cout << s1 << endl;
	}
}
int main()
{
	function();
	return 0;
}
#endif

/*
						1
					1   1   1
				1   2   3   2   1
			1   3   6   7   6   3   1
		1   4  10  16  19  16  10   4   1
	1   5  15  30  45  51  45  30  15   5   1
1   6  21  50  90 126 141 126  90  50  21   6   1
		————————————————

以上三角形的数阵，第一行只有一个数1，以下每行的每个数，是恰好是它上面的数，左上角数到右上角的数，
3个数之和（如果不存在某个数，认为该数就是0）。

求第n行第一个偶数出现的位置。如果没有偶数，则输出-1。例如输入3,则输出2，输入4则输出3。
*/
int get_triangle()
{
	int m = 0, n = 0;
	cin >> m;
	n = 2 * m - 1;
	vector<vector<int>> trg(m, vector<int>(n, 0));
	for (int i = 0; i < n; i++)
	{
		trg[i][0] = 1;
		trg[i][i * 2] = 1;
	}
}
int main()
{
	
	return 0;
}