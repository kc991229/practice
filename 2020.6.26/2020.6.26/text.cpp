#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int getValue(vector<int> gifts, int n)
{
	int len = gifts.size();
	int mid = 0;
	int num = 0;
	int* p = new int[len];
	for (int i = 0; i<len; i++)
	{
		p[i] = gifts[i];
	}
	sort(p, p + len);
	mid = p[len / 2];
	for (int i = 0; i < len; i++)
	{
		
		if (mid == p[i])
		{
			num++;
		}
		if (num >= len / 2)
		{
			return mid;
		}
	}
	return -1;
}
int main()
{
	int myints[] = { 1, 2, 3, 2, 2 };
	std::vector<int> fifth(myints, myints + sizeof(myints) / sizeof(int));
	cout << getValue(fifth, 5);
	return 0;
}
/*
Levenshtein 距离，又称编辑距离，指的是两个字符串之间，由一个转换成另一个所需的最少编辑操作次数.
许可的编辑操作包括将一个字符替换成另一个字符，插入一个字符，删除一个字符。
Ex：字符串A:abcdefg字符串B: abcdef通过增加或是删掉字符”g”的方式达到目的。
这两种方案都需要一次操作。把这个操作所需要的次数定义为两个字符串的距离。
要求：
给定任意两个字符串，写出一个算法计算它们的编辑距离。

输入描述：
输入两个字符串
输出描述：
得到计算结果
示例1:
输入
abcdefg
abcdef
输出
1
*/