#include <iostream>
#include <string>
using namespace std;
bool str_lenth(string s1, string s2)
{
	return s1.size() <= s2.size() ? true : false;
}
bool str_dire(string s1, string s2)
{
	string::iterator it = s1.begin();
	for (auto v : s2)
	{
		if (v > *it)
		{
			return true;
		}
		else if (v < *it)
		{
			return false;
		}
		it++;
		if (it == s1.end())
			return true;
	}
}
int judge_num(int num1, int num2)
{
	num1>num2 ? num1 = num1 : std::swap(num1, num2);
	int temp = 1;
	for (int i = 2; i<num2; i++)
	{
		if (num1%i == 0 && num2%i == 0)
		{
			temp = i;
		}
	}
	return num1*num2 / temp;
}
int main()
{
	int num = 0;
	cin >> num;
	if (num <= 0)
	{
		cout << "both";
		return 0;
	}
	string*p1 = new string[num];
	for (int i = 0; i < num; i++)
	{
		cin >> p1[i];
	}
	size_t judge_lenth = 1, judge_dirc = 1;
	for (int j = 0; j < num - 1; j++)
	{
		if (judge_lenth==1)
			judge_lenth = str_lenth(p1[j], p1[j + 1]);
		if (judge_dirc == 1)
			judge_dirc = str_dire(p1[j], p1[j + 1]);
	}
	if (judge_lenth ==1&& judge_dirc == 1)
		cout << "both";
	if (judge_lenth ==0&& judge_dirc == 0)
		cout << "none";
	if (judge_lenth == 0 && judge_dirc == 1)
		cout << "lexicographically";
	if (judge_lenth == 1 && judge_dirc == 0)
		cout << "lengths";
	return 0;
}