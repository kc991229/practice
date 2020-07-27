/*

输入两个字符串，从第一字符串中删除第二个字符串中所有的字符。
例如，输入”They are students.”和”aeiou”，则删除之后的第一个字符串变成”Thy r stdnts.”

输入描述:
每个测试输入包含2个字符串

输出描述:
输出删除后的字符串
示例1
输入
They are students.
aeiou
输出
Thy r stdnts.
*/
#include <iostream>
#include <string>
using namespace std;
void function1()
{
	string str1, str2;
	while (getline(cin, str1))
	{
		while (getline(cin, str2))
		{
			int arr[256] = { 0 };
			for (auto v : str2)
			{
				arr[v]++;
			}
			arr[32] = 0;
			for (auto v : str1)
			{
				if (arr[v] == 0)
					cout << v;
			}
			cout << endl;
		}
	}
}


/*
一个数组有 N 个元素，求连续子数组的最大和。 例如：[-1,2,1]，和最大的连续子数组为[2,1]，其和为 3

输入描述:
输入为两行。 第一行一个整数n(1 <= n <= 100000)，表示一共有n个元素 第二行为n个数，
即每个元素,每个整数都在32位int范围内。以空格分隔。

输出描述:
所有连续子数组中和最大的值。
示例1
输入
3
-1 2 1
输出
3
*/
void function2()
{
	int n, curSum = 0, maxSum = -1e5;
	cin >> n;
	int arr[100];
	for (int i = 0; i<n; i++)
	{
		cin >> arr[i];
		curSum += arr[i];
		if (curSum>maxSum){
			maxSum = curSum;
		}
		if (curSum<0){
			curSum = 0;
		}
	}
	cout << maxSum << endl;
	return 0;
}



/*
问题描述：给出4个1-10的数字，通过加减乘除，得到数字为24就算胜利
输入：
4个1-10的数字。[数字允许重复，但每个数字仅允许使用一次，测试用例保证无异常数字]
输出：
true or false

输入描述:
输入4个int整数

输出描述:
返回能否得到24点，能输出true，不能输出false

示例1
输入
7 2 1 10
输出
true
*/
链接：https://www.nowcoder.com/questionTerminal/fbc417f314f745b1978fc751a54ac8cb
来源：牛客网

#include<iostream>
using namespace std;

inline void Swap(int &a, int &b)
{
	int temp = a;
	a = b;
	b = temp;
}

bool is24(int a[], int begin, int end, double tot)
{
	if (begin == end - 1) return (a[begin] == tot);
	else
	{
		bool ans = false;
		for (int i = begin; i<end; i++)
		{
			swap(a[i], a[end - 1]);
			ans = ans || is24(a, begin, end - 1, tot + a[end - 1]) || is24(a, begin, end - 1, tot - a[end - 1]) || is24(a, begin, end - 1, tot * a[end - 1]) || is24(a, begin, end - 1, tot / a[end - 1]);
			swap(a[i], a[end - 1]);
		}
		return ans;
	}


}

int main()
{
	int a[4];
	while (cin >> a[0] >> a[1] >> a[2] >> a[3])
	{
		if (is24(a, 0, 4, 24)) cout << "true" << endl;
		else cout << "false" << endl;
	}
}