/*

���������ַ������ӵ�һ�ַ�����ɾ���ڶ����ַ��������е��ַ���
���磬���롱They are students.���͡�aeiou������ɾ��֮��ĵ�һ���ַ�����ɡ�Thy r stdnts.��

��������:
ÿ�������������2���ַ���

�������:
���ɾ������ַ���
ʾ��1
����
They are students.
aeiou
���
Thy r stdnts.
*/
#include <iostream>
#include <string>
using namespace std;
void function1()
{
	string str1, str2;
	while (getline(cin, str1))
	{
		while (getline(cin, str2))
		{
			int arr[256] = { 0 };
			for (auto v : str2)
			{
				arr[v]++;
			}
			arr[32] = 0;
			for (auto v : str1)
			{
				if (arr[v] == 0)
					cout << v;
			}
			cout << endl;
		}
	}
}


/*
һ�������� N ��Ԫ�أ�����������������͡� ���磺[-1,2,1]������������������Ϊ[2,1]�����Ϊ 3

��������:
����Ϊ���С� ��һ��һ������n(1 <= n <= 100000)����ʾһ����n��Ԫ�� �ڶ���Ϊn������
��ÿ��Ԫ��,ÿ����������32λint��Χ�ڡ��Կո�ָ���

�������:
���������������к�����ֵ��
ʾ��1
����
3
-1 2 1
���
3
*/
void function2()
{
	int n, curSum = 0, maxSum = -1e5;
	cin >> n;
	int arr[100];
	for (int i = 0; i<n; i++)
	{
		cin >> arr[i];
		curSum += arr[i];
		if (curSum>maxSum){
			maxSum = curSum;
		}
		if (curSum<0){
			curSum = 0;
		}
	}
	cout << maxSum << endl;
	return 0;
}



/*
��������������4��1-10�����֣�ͨ���Ӽ��˳����õ�����Ϊ24����ʤ��
���룺
4��1-10�����֡�[���������ظ�����ÿ�����ֽ�����ʹ��һ�Σ�����������֤���쳣����]
�����
true or false

��������:
����4��int����

�������:
�����ܷ�õ�24�㣬�����true���������false

ʾ��1
����
7 2 1 10
���
true
*/
���ӣ�https://www.nowcoder.com/questionTerminal/fbc417f314f745b1978fc751a54ac8cb
��Դ��ţ����

#include<iostream>
using namespace std;

inline void Swap(int &a, int &b)
{
	int temp = a;
	a = b;
	b = temp;
}

bool is24(int a[], int begin, int end, double tot)
{
	if (begin == end - 1) return (a[begin] == tot);
	else
	{
		bool ans = false;
		for (int i = begin; i<end; i++)
		{
			swap(a[i], a[end - 1]);
			ans = ans || is24(a, begin, end - 1, tot + a[end - 1]) || is24(a, begin, end - 1, tot - a[end - 1]) || is24(a, begin, end - 1, tot * a[end - 1]) || is24(a, begin, end - 1, tot / a[end - 1]);
			swap(a[i], a[end - 1]);
		}
		return ans;
	}


}

int main()
{
	int a[4];
	while (cin >> a[0] >> a[1] >> a[2] >> a[3])
	{
		if (is24(a, 0, 4, 24)) cout << "true" << endl;
		else cout << "false" << endl;
	}
}