/*
һֻ���������ÿ���ܲ���һ̥���ӡ�ÿֻС���ӵĳ�������һ�졣 ĳ��������һֻС���ӡ�
���ʵ�N���Ժ�������õ�����ֻ���ӡ�

��������:
�������ݰ������飬ÿ��һ�У�Ϊ����n(1��n��90)��

�������:
��Ӧ�����n���м�ֻ����(����û��������������)��
ʾ��1
���룺
1
2
�����
1
2
*/
#include <iostream>
#include <string>
using namespace std;
long function(long day)
{
	if (day == 1)
		return 1;
	if (day == 2)
		return 2;
	long count = 0;
	long last = 1, next = 2;
	for (int i = 2; i < day; i++)
	{
		count = last + next;
		last = next;
		next = count;
	}
	return count;
}


/*

NowCoderÿ��Ҫ�����ͻ�д�����ʼ�����������֪�����һ���ʼ��а�������ռ��ˣ�
�ռ�������֮�����һ�����źͿո����������ռ�������Ҳ�����ո�򶺺ţ���������Ҫ��˫���Ű�����
���ڸ���һ���ռ����������������������Ӧ���ռ����б�

��������:
��������������ݡ�

ÿ�����ݵĵ�һ����һ������n (1��n��128)����ʾ������n��������

������n�У�ÿһ�а���һ���ռ��˵��������������Ȳ�����16���ַ���

�������:
��Ӧÿһ�����룬���һ���ռ����б�
ʾ��1
����
3
Joe
Quan, William
Letendre,Bruce
2
Leon
Kewell
���
Joe, "Quan, William", "Letendre,Bruce"
Leon, Kewell
*/


int main()
{
	int n;
	while (cin >> n)
	{
		getchar(); //ˢ�»�����
		while (n--)
		{
			string str;
			getline(cin, str);
			if (str.find(',') != -1 || str.find(' ') != -1)
			{
				str.insert(str.begin(), '"');
				str.insert(str.end(), '"');
			}
			if (n == 0)
				cout << str << endl;
			else
				cout << str << ", ";
		}
	}
	return 0;
}