#include <iostream>
using namespace std;

/*��һ���������������������㰴�����һ��һ��ش����������α�ţ�
�������Ϊ1��������������� a��b�������һ���㷨�����a��b�������������ȵı�š�
��������int a,b��Ϊ�������ı�š�*/
class LCA {
public:
	int getLCA(int a, int b) {
		if (a>b)
			swap(a, b);
		while (a != b)
		{
			if (b>a)
			{
				while (b>a)
				{
					b = b / 2;
				}
			}
			else if (b<a)
			{
				while (b<a)
					a = a / 2;
			}
		}
		return a;
	}
};

/*
��һ��byte���ֶ�Ӧ�Ķ�����������1�����������������3�Ķ�����Ϊ00000011���������2��1
����: һ��byte�͵�����
*/

size_t get_num_1(size_t byte)
{
	size_t max = 0, temp = 0;
	while (byte)
	{
		while (byte & 1)
		{
			temp++;
			byte = byte >> 1;
		}
		if (max < temp)
		{
			max = temp;
			temp = 0;
		}
		else
			temp = 0;
		byte = byte >> 1;
	}
	return max;
}
int main()
{
	size_t byte = 0;
	cin >> byte;
	cout << get_num_1(byte);
	return 0;
}