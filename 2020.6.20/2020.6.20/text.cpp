#include <iostream>
#include <string>
#include <assert.h>
using namespace std;
/*��һֻ���ӣ��ӳ������3������ÿ���¶���һֻ���ӣ�
С���ӳ����������º�ÿ��������һֻ���ӣ��������Ӷ���������ÿ���µ���������Ϊ���٣�*/

/*
���⣺����д������ֵ���й۲죬1 1 2 3 5 8 
���Կ�����һ��쳲���������

���߼��Ƕȷ��������µ�������=�ϸ��µ�������+����������������
��������������=������ǰ��������������Ϊ�����º���Щ���Ӷ�����������

�������ʹ�õݹ�д��
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
�ڼ�����У�ͨ���һ�������﷨���㷺Ӧ�����ļ����������ݿ⡢������ʽ��������Ҫ���λʵ���ַ���ͨ������㷨��
Ҫ��
ʵ������2��ͨ�����
*��ƥ��0�������ϵ��ַ����ַ���Ӣ����ĸ������0-9��ɣ������ִ�Сд����ͬ��
����ƥ��1���ַ�
���룺
te?t*.*
txtt222.xls
�����
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