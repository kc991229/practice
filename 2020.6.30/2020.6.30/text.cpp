#if 0
/*
小喵们很喜欢把自己装进容器里的（例如碗），但是要是碗的周长比喵的身长还短，它们就进不去了。
现在告诉你它们的身长，和碗的半径，请判断一下能否到碗里去。

输入描述:
输入有多组数据。

每组数据包含两个整数n (1≤n≤2^128) 和r (1≤r≤2^128)，分别代表喵的身长和碗的半径。
圆周率使用3.14。

输出描述:
对应每一组数据，如果喵能装进碗里就输出“Yes”；否则输出“No”。
输入
6 1
7 1
9876543210 1234567890
输出
Yes
No
No
*/
#include <iostream>
#include <string>
using namespace std;
#define pi 3.14
string& calculate(string len2)
{

}
bool judge_lenth(string len1, string len2)
{
	//len2=calculate(len2);
	if (len1.size() > len2.size())
		return true;
	else if (len1.size() < len2.size())
		return false;
	else
	{
		string::iterator it1 = len1.begin();
		string::iterator it2 = len2.begin();
		while (it1 != len1.end() && it2 != len2.end())
		{
			if (*it1 > *it2)
				return true;
			else if (*it1 < *it2)
				return false;
			else
			{
				it1++;
				it2++;
			}
		}
		return true;
	}
}
int main()
{
	cout << pi;
}
#endif
#if 1
/*
一只青蛙一次可以跳上1级台阶，也可以跳上2级……它也可以跳上n级。
求该青蛙跳上一个n级的台阶总共有多少种跳法。

解：递归思想，一共n个台阶，恒有一种即一次跳n个。
第一次跳有一次跳1，2，3...n-1，之后对于剩余的台阶，亦有一次跳1，2，3...
因此：f(n)=f(1)+f(2)+f(3)...f(n-1)+1
*/
#include <iostream>
#include <string>
using namespace std;
int jumpFloorII(int number) 
{
	int count = 1;
	if (number == 1)
		return 1;
	else
	{
		while (--number)
		{
			count += jumpFloorII(number);
		}
	}
	return count;
}
int main()
{
	int i = 0;
	while (cin >> i)
	{
		cout << jumpFloorII(i) << endl;
	}
	return 0;
}
#endif