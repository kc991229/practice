/*
��������ͨ����һ�����ĸ���λ�ϵ����ּ������õ�������õ�������һλ������ô���������������
����������λ�����߰�������λ�����֣���ô�ٰ���Щ���ּ�������

��˽�����ȥ��ֱ���õ���һλ��Ϊֹ�����磬����24 ��˵����2 ��4 ��ӵõ�6������6 ��һλ����
���6 ��24 ���������ٱ���39����3 ��9 �������õ�12������12 ����һλ������˻��ð�1 ��2 ��������
���õ�3������һ��һλ�������3 ��39 �����������ڸ���һ�����������������������
��������:
��������������ݡ�

ÿ���������ݰ���һ��������n��1��n��10E1000��ע�ⷶΧ��
*/
#include <iostream>
#include <string>
using namespace std;
string ChangeStr_Num(int num)
{
	string str;
	while (num)
	{
		str += num % 10 + '0';
		num /= 10;
	}
	return str;
}
size_t GetNumRoot(string str)
{
	int num = 0, temp = 0;
	for (auto v : str)
	{
		num += v - '0';
	}
	while (num)
	{
		temp += num % 10;
		num /= 10;
	}
	if (temp < 10)
		return temp;
	else
	{
		return GetNumRoot(ChangeStr_Num(temp));
	}
}
int main()
{
	string str;
	while (cin >> str)
	{
		cout << GetNumRoot(str) << endl;
	}
}
