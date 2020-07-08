/*
一块花布条，里面有些图案，另有一块直接可用的小饰条，里面也有一些图案。对于给定的花布条和小饰条，
计算一下能从花布条中尽可能剪出几块小饰条来呢？

输入描述:
每组数据包含两个字符串s,t，分别是成对出现的花布条和小饰条，其布条都是用可见ASCII字符表示的，
可见的ASCII字符有多少个，布条的花纹也有多少种花样。花纹条和小饰条不会超过1000个字符长。

输出描述:
对应每组输入，输出能从花纹布中剪出的最多小饰条个数，如果一块都没有，那就输出0，每个结果占一行。
示例1
输入
abcde a3
aaaaaa aa
输出
0
3
*/
#include <iostream>
#include <string>
using namespace std;

void function()
{
	string s, t;
	while (cin >> s >> t)
	{
		int count = 0;
		int pos = 0;
		while (s.find(t, pos) != string::npos)
		{
			count++;
			pos = s.find(t, pos) + t.size();
		}
		cout << count << endl;
	}
}

/*
NowCoder开了一家早餐店，这家店的客人都有个奇怪的癖好：他们只要来这家店吃过一次早餐，就会每天都过来；
并且，所有人在这家店吃了两天早餐后，接下来每天都会带一位新朋友一起来品尝。
于是，这家店的客人从最初一个人发展成浩浩荡荡成百上千人：1、1、2、3、5……
现在，NowCoder想请你帮忙统计一下，某一段时间范围那他总共卖出多少份早餐（假设每位客人只吃一份早餐）。

输入描述:
测试数据包括多组。
每组数据包含两个整数from和to(1≤from≤to≤80)，分别代表开店的第from天和第to天。

输出描述:
对应每一组输入，输出从from到to这些天里（包含from和to两天），需要做多少份早餐。
*/
#include <iostream>
int Fibonacci(int num)
{
	if (num == 1 || num == 2)
		return 1;
	int count1 = 0;
	int a = 1, b = 1;
	while (num >= 3)
	{
		count1 = a + b;
		a = b;
		b = count1;
		num--;
	}
	return count1;
}
void function1()
{
	int from, to;
	while (cin >> from >> to)
	{
		int count = 0;
		while (from <= to)
		{
			count += Fibonacci(from);
			from++;
		}
		cout << count << endl;
	}
}
int main()
{
	function1();
	return 0;
}