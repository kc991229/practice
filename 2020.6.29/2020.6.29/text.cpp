/*
数根可以通过把一个数的各个位上的数字加起来得到。如果得到的数是一位数，那么这个数就是数根；
如果结果是两位数或者包括更多位的数字，那么再把这些数字加起来。

如此进行下去，直到得到是一位数为止。比如，对于24 来说，把2 和4 相加得到6，由于6 是一位数，
因此6 是24 的数根。再比如39，把3 和9 加起来得到12，由于12 不是一位数，因此还得把1 和2 加起来，
最后得到3，这是一个一位数，因此3 是39 的数根。现在给你一个正整数，输出它的数根。
输入描述:
输入包含多组数据。

每组数据数据包含一个正整数n（1≤n≤10E1000）注意范围。
*/
#include <iostream>
#include <string>
using namespace std;
string ChangeStr_Num(int num)
{
	string str;
	while (num)
	{
		str += num % 10 + '0';
		num /= 10;
	}
	return str;
}
size_t GetNumRoot(string str)
{
	int num = 0, temp = 0;
	for (auto v : str)
	{
		num += v - '0';
	}
	while (num)
	{
		temp += num % 10;
		num /= 10;
	}
	if (temp < 10)
		return temp;
	else
	{
		return GetNumRoot(ChangeStr_Num(temp));
	}
}
int main()
{
	string str;
	while (cin >> str)
	{
		cout << GetNumRoot(str) << endl;
	}
}
