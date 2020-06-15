#include <iostream>

using namespace std;

/*
有两个32位整数n和m，请编写算法将m的二进制数位插入到n的二进制的第j到第i位,
其中二进制的位数从低位数到高位且以0开始。

给定两个数int n和int m，同时给定int j和int i，意义如题所述，请返回操作后的数，
保证n的第j到第i位均为零，且m的二进制位数小于等于i-j+1。

测试样例：
1024，19，2，6
返回：1100
*/

//先将m左移j位，保证对应的位可以进行或运算，然后逻辑或即可
int binInsert(int n, int m, int j, int i) {
	m = m << j;
	n = n | m;
	return n;
}

/*
任意一个偶数（大于2）都可以由2个素数组成，组成偶数的2个素数有很多种情况，
本题目要求输出组成指定偶数的两个素数差值最小的素数对

输入描述:
输入一个偶数

输出描述:
输出两个素数

示例1
输入：20
输出：7 13
*/
int check_num(int num)//是素数返回1，不是返回0
{
	for (int i = 2; i <= sqrt((double)num); i++)
	{
		if (num%i == 0)
			return 0;
	}
	return 1;
}

void find(int num)
{
	int temp1 = num / 2;
	int temp2 = num / 2;
	for (; temp1>0, temp2<num; temp1--, temp2++)
	{
		if (check_num(temp1) && check_num(temp2))
		{
			cout << temp1 << endl << temp2<<endl;
			return;
		}

	}
}
int main()
{
	int n = 0;
	while (cin >> n)
	{
		if (n == 2)
		{
			cout << 1 << endl << 2 << endl;
			return 0;
		}
		find(n);
	}
	return 0;
}