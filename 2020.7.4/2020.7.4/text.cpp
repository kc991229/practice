#if 0
/*
一个正整数可以分解成一个或多个数组的积。例如36=2*2*3*3，即包含2和3两个因子。NowCoder最近在研究因子个数的分布规律，现在给出一系列正整数，他希望你开发一个程序输出每个正整数的因子个数。

输入:
输入包括多组数据。
每组数据仅有一个整数n (2≤n≤100000)。

输出:
对应每个整数，输出其因子个数，每个结果占一行。
示例1
输入:
30
26
20
输出
3
2
2
*/
#include <iostream>
#include <math.h>
#include <set>
using namespace std;
set<int> s;
bool judge_prime(int num)//判断素数，是返回1不是返回0
{
	if (num == 2)
		return true;
	for (int i = 2; i <= sqrt((double)num); i++)
	{
		if (num%i == 0)
			return false;
	}
	return true;
}
void Get_Fac_Count(int num)
{
	if (judge_prime(num))
	{
		s.insert(num);
		return;
	}
		
	int i = 0, j = 0;
	for (i = 2; i <= sqrt((double)num); i++)
	{
		if (num%i == 0)
		{
			s.insert(i);
			Get_Fac_Count(num / i);
			return;
		}
	}
}
int main()
{
	int i = 0;
	while (cin >> i)
	{
		if (judge_prime(i))
		{
			cout << "1" << endl;
			continue;
		}
		s.clear();
		Get_Fac_Count(i);
		cout << s.size() << endl;
	}
}
#endif
#if 1
/*
NowCoder生活在充满危险和阴谋的年代。为了生存，他首次发明了密码，用于军队的消息传递。
假设你是军团中的一名军官，需要把发送来的消息破译出来、并提
供给你的将军。
消息加密的办法是：对消息原文中的每个字母，分别用该字母之后的第5个字母替换
例如：消息原文中的每个字母A 都分别替换成字母F），其他字符不变，并且消息原文的所有字母都是大写的。
密码中的字母与原文中的字母对应关系如下。
密码字母：A B C D E F G H I J K L M N O P Q R S T U V W X Y Z
原文字母：V W X Y Z A B C D E F G H I J K L M N O P Q R S T U

输入描述:
输入包括多组数据，每组数据一行，为收到的密文。
密文仅有空格和大写字母组成。


输出描述:
对应每一组数据，输出解密后的明文。
*/
#include <iostream>
#include <string>
using namespace std;
int main()
{
	string str;
	while (getline(cin,str))
	{
		string::iterator it = str.begin();
		for (; it != str.end(); it++)
		{
			if (*it >= 'F' && *it <= 'Z')
			{
				*it -= 5;
			}
			else if (*it >= 'A' && *it <= 'E')
			{
				*it += 21;
			}
			else
				*it = ' ';
		}
		for (auto v : str)
			cout << v;
		cout << endl;
	}
	return 0;
}
#endif