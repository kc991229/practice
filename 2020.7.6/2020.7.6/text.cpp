/*
��ν���ӷֽ⣬���ǰѸ�����������a���ֽ�����ɸ������ĳ˻����� a = a1 �� a2 �� a3 �� ... �� an,
���� 1 < a1 �� a2 �� a3 �� ... �� an������a1��a2��...��an��Ϊ������ �ȸ���һ������a��������ֽ������ӡ�

��������:
��������������ݣ�ÿ�����ݰ���һ��������a��2��a��1000000����

�������:
��Ӧÿ�����ݣ��ԡ�a = a1 * a2 * a3...������ʽ�����ʽ�ֽ��Ľ����
ʾ��1
����
10
18
���
10 = 2 * 5
18 = 2 * 3 * 3
*/
#include <iostream>
#include <algorithm>
using namespace std;
void function()
{
	int num = 0;
	while (cin >> num)
	{
		cout << num << " = ";
		for (int i = 2; i <= sqrt((double)num); i++)
		{
			while (num != i)
			{
				if (num%i == 0)
				{
					cout << i << " * ";
					num /= i;
				}
				else
					break;
			}
		}
		cout << num << endl;
	}
}
int main()
{
	function();
	return 0;
}



