/*
nowcoder�����У�A��B��ƹ�����к�˫ϲ�ġ��������ǵġ���
��������Ҫ�б�A���Ƿ������B�������е����࣬����ÿ���������������B���е�����������ô���أ�

��������:
�����ж������ݡ�
ÿ�����ݰ��������ַ���A��B������A����B���е�ƹ����ÿ��ƹ������һ����д��ĸ��ʾ������ͬ���͵�ƹ����Ϊ��ͬ�Ĵ�д��ĸ��
�ַ������Ȳ�����10000��

�������:
ÿһ�������Ӧһ����������B�����������������A�ж��У�����ÿ�����������������A���������Yes�������������No����
ʾ��1
����
ABCDFYE CDE
ABCDGEAS CDECDE
���
Yes
No
*/
#include <iostream>
#include <string>
using namespace std;
bool function1(string str1,string str2)
{
	int arr1[26] = { 0 };
	int arr2[26] = { 0 };
	for (auto s : str1)
	{
		arr1[s - 'A']++;
	}
	for (auto s : str2)
	{
		arr2[s - 'A']++;
	}
	for (int i = 0; i < 26; i++)
	{
		if (arr1[i] < arr2[i])
		{
			return false;
		}
	}
	return true;
}
int main()
{
	string str1, str2;
	while (cin >> str1 >> str2)
	{
		if (function1(str1, str2))
			cout << "Yes" << endl;
		else
			cout << "No" << endl;
	}
}