#include <iostream>
#include <string>
//将一句话进行倒置，标点不倒置。例如：I like bejing.   ->   bejing. like I
void resever(std::string::iterator s1, std::string::iterator s2)
{
	while (s1 < s2)
	{
		std::swap(*s1, *s2);
		s1++;
		s2--;
	}
}
void resever_str()
{
	std::string str;
	std::getline(std::cin, str);
	resever(str.begin(), str.end() - 1);
	std::string::iterator head = str.begin();
	std::string::iterator tail = str.begin()+1;
	while (tail !=str.end())
	{
		while (*tail == ' ')
		{
			resever(head, tail - 1);
			head = tail+1;
			tail++;
			continue;
		}
		tail++;
		
	}
	resever(head, tail - 1);
	for (auto v : str)
	{
		std::cout << v;
	}
}
//牛牛定义排序子序列为一个数组中一段连续的子序列, 并且这段子序列是非递增或者非递减排序的。牛牛有一个长度为n的整数数组A, 他现在有一个任务是把数组A分为若干段排序子序列, 牛牛想知道他最少可以把这个数组分为几段排序子序列.
//如样例所示, 牛牛可以把数组A划分为[1, 2, 3]和[2, 2, 1]两个排序子序列, 至少需要划分为2个排序子序列, 所以输出2
//输入描述 :
//输入的第一行为一个正整数n(1 ≤ n ≤ 10 ^ 5) 第二行包括n个整数A_i(1 ≤ A_i ≤ 10 ^ 9), 表示数组A的每个数字。
//输出描述 :
//输出一个整数表示牛牛可以将A最少划分为多少段排序子序列

#include<vector>
using namespace std;
int NUINIU_sort()
{
	int i = 0;
	int count = 0;
	int n;
	vector<int> vres;
	cin >> n;
	vres.resize(n + 1);
	for (int i = 0; i < n; i++)
	{
		cin >> vres[i];
	}
	while (i < n)
	{
		if (vres[i] < vres[i + 1])
		{
			while (i < n && vres[i] < vres[i + 1])
			{
				i++;
			}
			i++;
			count++;
		}
		else if (i < n && vres[i] == vres[i + 1])
		{
			i++;
		}

		else if (vres[i] > vres[i + 1])
		{
			while (i < n && vres[i] > vres[i + 1])
			{
				i++;
			}
			i++;
			count++;
		}
	}
	return count;
}


