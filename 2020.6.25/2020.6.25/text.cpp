#include <iostream>
#include <string>
using namespace std;

//找出字符串中第一个只出现一次的字符
void function()
{
	string str;
	
	while (cin >> str)
	{
		char first_str = 0, s;
		int i = str.size(), num = 0;
		int arr[256] = { 0 };
		for (auto v : str)
		{
			arr[v]++;
		}
		for (int j = 0; j < 256; j++)
		{
			if (arr[j] == 1)
			{
				num++;
				s = j;
				if (str.find(s) <= i)
				{
					first_str = s;
					i = str.find(s);
				}
			}
		}
		if (num == 0)
		{
			cout << -1<< endl;
		}
		else
		{
			cout << first_str << endl;
		}
	}
}
int main()
{
	function();
	return 0;
}