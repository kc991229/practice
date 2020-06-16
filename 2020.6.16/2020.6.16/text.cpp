#include <iostream>
using namespace std;
/*
题目描述
根据输入的日期，计算是这一年的第几天。。

详细描述：

输入某年某月某日，判断这一天是这一年的第几天？
*/
static const int arr[] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
static const int arr1[] = { 0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
bool judge_leap(int year)
{
	if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
		return true;
	return false;
}
bool judge_ture(int year, int month, int day)
{
	if (year <= 0 || month >= 13 || day >= 32 || month <= 0 || day <= 0)
		return false;
	if (month == 2 && judge_leap(year))
	{
		if (day <= 29)
			return true;
		else
			return false;
	}
	else
	{
		if (day <= arr[month])
			return true;
		else
		{
			return false;
		}
	}
}
int ConverDateToDay(int year, int month, int day)
{
	int nums = 0;
	if (judge_leap(year))
	{
		for (size_t i = 1; i<month; i++)
		{
			nums += arr1[i];
		}
		nums += day;
	}
	else
	{
		for (size_t i = 1; i<month; i++)
		{
			nums += arr[i];
		}
		nums += day;
	}
	return nums;
}
int function(int year, int month, int day)
{
	if (judge_ture(year, month, day))
		return ConverDateToDay(year, month, day);
	else
	{
		return -1;
	}
}
int main()
{
	int year, month, day;
	while (cin >> year >> month >> day)
	{
		cout << function(year, month, day) << endl;
	}
	return 0;
}
