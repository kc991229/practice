#if 0
//������ʹ��+��-��*��/���������ĺ�
#include <iostream>
using namespace std;
int Add(int num1, int num2)
{
	if ((num1&num2) == 0)
	{
		return num1 | num2;
	}
	int temp1 = 0, temp2 = 0;
	temp1 = num1&num2;
	temp1 = temp1 << 1;
	temp2 = num1 ^ num2;
	return Add(temp1, temp2);
}
int main()
{
	int i, j;
	while (cin >> i >> j)
	{
		cout << Add(i, j) << endl;
	}
	return 0;
}
#endif
#if 1
/*
���������ߣ������ж�һ���ܲ������һ�������Ρ�

��������:
��������������ݣ�ÿ�����ݰ�������������a��b��c��1��a, b, c��10^100����

�������:
��Ӧÿһ�����ݣ�������������һ�������Σ��������Yes�������������No��
*/
#include <iostream>
#include <string>
using namespace std;
string str_add(string str1, string str2)
{
	if (str1.size()<str2.size())
		std::swap(str1, str2);
	string res;
	int ret = 0;
	int num = 1;
	string::reverse_iterator it2 = str2.rbegin();
	string::reverse_iterator it1 = str1.rbegin();
	while ( it2 != str2.rend() && it1 != str1.rend())
	{
		int temp = 0;
		temp = (*it1 - '0' + *it2 - '0' + ret) % 10;
		ret = (*it1 - '0' + *it2 - '0' + ret) / 10;
		res += (temp + '0');
		if (it2 + 1 == str2.rend())
			res += ret + '0';
	}
	while (it1 != str1.rend())
	{
		if (num)
		{

		}
		res += *it1;
		it1++;
	}
	string str_temp;
	string::reverse_iterator it3 = res.rbegin();
	while (it3 != res.rend())
	{
		str_temp += *it3;
		it3++;
	}
	return str_temp;
}
//�ж��������ִ��Ĵ�С��ǰ�ߴ󷵻�1�����ߴ������ȷ���0
bool judge_strnum_size(string str1, string str2)
{
	if (str1.size() > str2.size())
		return true;
	else if (str1.size() < str2.size())
		return false;
	else
	{
		string::iterator it1 = str1.begin();
		string::iterator it2 = str2.begin();
		while (it1 != str1.end() && it2 != str2.end())
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
		return false;
	}
}
int main()
{
	string str1, str2, str3;
	while (cin >> str1 >> str2>> str3)
	{
		if (judge_strnum_size(str_add(str1, str2), str3) &&
			judge_strnum_size(str_add(str1, str3), str2) &&
			judge_strnum_size(str_add(str2, str3), str1))
			cout << "Yes" << endl;
		else
			cout << "No" << endl;
	}
	return 0;
}
#endif