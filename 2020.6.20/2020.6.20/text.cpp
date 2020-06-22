#include <iostream>
#include <string>
#include <assert.h>
using namespace std;
/*有一只兔子，从出生后第3个月起每个月都生一只兔子，
小兔子长到第三个月后每个月又生一只兔子，假如兔子都不死，问每个月的兔子总数为多少？*/

/*
解题：首先写出几组值进行观察，1 1 2 3 5 8 
可以看出是一组斐波那契数。

从逻辑角度分析：该月的兔子数=上个月的兔子数+该月生的兔子数。
该月生的兔子数=两个月前的兔子数——因为两个月后这些兔子都可以生兔子

代码可以使用递归写法
*/
int getRabbitNum(int month)
{
	assert(month >= 0);
	if (month < 3)
	{
		return 1;
	}
	return getRabbitNum(month - 1) + getRabbitNum(month - 2);
}

/*
在计算机中，通配符一种特殊语法，广泛应用于文件搜索、数据库、正则表达式等领域。现要求各位实现字符串通配符的算法。
要求：
实现如下2个通配符：
*：匹配0个或以上的字符（字符由英文字母和数字0-9组成，不区分大小写。下同）
？：匹配1个字符
输入：
te?t*.*
txtt222.xls
输出：
false
*/
bool CheckStringSame( string str1,  string str2)
{
	string::iterator it1 = str1.begin();
	string::iterator it2 = str2.begin();
	if (*(str1.end() - 1) == '*')
		return true;
	while (it1 != str1.end() && it2 != str2.end())
	{
		if (*it1 == *it2)
		{
			it1++;
			it2++;
			continue;
		}
		if (*it1 == '?')
		{
			it1++;
			it2++;
		}
		else if (*it1 == '*')
		{
			if (*(it2 + 1) == *(it1 + 1))
			{
				it1++;
				it2++;
			}
			else if (*it2 == *(it1 + 1))
			{
				it2++;
				it1++;
				it1++;

			}
			else
				it2++;
		}
		else
		{
			return false;
		}
	}
	if (it1 == str1.end() && it2 != str2.end())
		return false;
	if (it1 != str1.end() && it2 == str2.end())
		return true;
	if (it1 == str1.end() && it2 == str2.end())
		return true;
}
int main()
{
	string str1, str2;
	while (cin >> str1 >> str2)
	{
		if (CheckStringSame(str1, str2))
			cout << "true" << endl;
		else
			cout << "false" << endl;
	}
	return 0;
}