#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int getValue(vector<int> gifts, int n)
{
	int len = gifts.size();
	int mid = 0;
	int num = 0;
	int* p = new int[len];
	for (int i = 0; i<len; i++)
	{
		p[i] = gifts[i];
	}
	sort(p, p + len);
	mid = p[len / 2];
	for (int i = 0; i < len; i++)
	{
		
		if (mid == p[i])
		{
			num++;
		}
		if (num >= len / 2)
		{
			return mid;
		}
	}
	return -1;
}
int main()
{
	int myints[] = { 1, 2, 3, 2, 2 };
	std::vector<int> fifth(myints, myints + sizeof(myints) / sizeof(int));
	cout << getValue(fifth, 5);
	return 0;
}
/*
Levenshtein ���룬�ֳƱ༭���룬ָ���������ַ���֮�䣬��һ��ת������һ����������ٱ༭��������.
��ɵı༭����������һ���ַ��滻����һ���ַ�������һ���ַ���ɾ��һ���ַ���
Ex���ַ���A:abcdefg�ַ���B: abcdefͨ�����ӻ���ɾ���ַ���g���ķ�ʽ�ﵽĿ�ġ�
�����ַ�������Ҫһ�β������������������Ҫ�Ĵ�������Ϊ�����ַ����ľ��롣
Ҫ��
�������������ַ�����д��һ���㷨�������ǵı༭���롣

����������
���������ַ���
���������
�õ�������
ʾ��1:
����
abcdefg
abcdef
���
1
*/