#include <iostream>
#include <string>
#include <vector>
using namespace std;
#if 0
/*
�����һ���㷨������������������ļӷ���
���룺
99999999999999999999999999999999999999999999999999
1
�����
100000000000000000000000000000000000000000000000000
*/
string arr("0123456789");
void str_sum(string& str, int end, int i)
{
	int num = 0, sum = 0;
	num = arr.find(str[end]);
	sum = num + i;
	if (sum < 10)
	{
		str[end] = arr[sum];
	}
	else
	{
		sum = sum - 10;
		str[end] = arr[sum];
		if (end != 0)
		{
			str_sum(str, end - 1, 1);
		}
		else
		{
			str[0] = '0';
			str = '1' + str;
		}
	}
}
void function()
{
	string s1, s2;
	while (cin >> s1 >> s2)
	{
		if (s1.size() < s2.size())
			swap(s1, s2);
		int i = s2.size();
		int j = 1;
		while (i--)
		{
			int num = arr.find(*(s2.end() - 1));
			str_sum(s1, s1.size() - j, num);
			s2.pop_back();
			j++;
		}
		cout << s1 << endl;
	}
}
int main()
{
	function();
	return 0;
}
#endif

/*
						1
					1   1   1
				1   2   3   2   1
			1   3   6   7   6   3   1
		1   4  10  16  19  16  10   4   1
	1   5  15  30  45  51  45  30  15   5   1
1   6  21  50  90 126 141 126  90  50  21   6   1
		��������������������������������

���������ε����󣬵�һ��ֻ��һ����1������ÿ�е�ÿ��������ǡ������������������Ͻ��������Ͻǵ�����
3����֮�ͣ����������ĳ��������Ϊ��������0����

���n�е�һ��ż�����ֵ�λ�á����û��ż���������-1����������3,�����2������4�����3��
*/
int get_triangle()
{
	int m = 0, n = 0;
	cin >> m;
	n = 2 * m - 1;
	vector<vector<int>> trg(m, vector<int>(n, 0));
	for (int i = 0; i < n; i++)
	{
		trg[i][0] = 1;
		trg[i][i * 2] = 1;
	}
}
int main()
{
	
	return 0;
}