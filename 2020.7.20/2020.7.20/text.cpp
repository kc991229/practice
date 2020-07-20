/*

输入两个整数 n 和 m，从数列1，2，3.......n 中随意取几个数,使其和等于 m ,要求将其中所有的可能组合列出来

输入描述:
每个测试输入包含2个整数,n和m

输出描述:
按每个组合的字典序排列输出,每行输出一种组合
示例1
输入
5 5
输出
1 4
2 3
5
*/
#include<iostream>
#include<vector>
using namespace std;
void help(int n, int m, vector<int>& v, int beg) //n从1到n，m为和
{
	//if (beg>n) return;
	if (m == 0) 
	{
		for (int i = 0; i<v.size(); i++)
		{
			i == 0 ? cout << v[i] : cout << " " << v[i];
		}
		cout << endl;
	}
	for (int i = beg; i <= n&&i <= m; i++) 
	{
		v.push_back(i);
		help(n, m - i, v, i + 1);
		v.pop_back();
	}
}
int main()
{
	int n, m;
	while (cin >> n >> m) 
	{
		vector<int>v;
		help(n, m, v, 1);
	}
}

#if 0
#include<iostream>
#include<string>
#include<set>
using namespace std;
int main()
{
	string s;
	int length;
	string NUM = "22233344455566677778889999";
	while (cin >> length)
	{
		set<string> data;
		int cnt;
		for (int i = 0; i < length; i++)
		{
			cnt = 0;
			string res;
			cin >> s;
			for (int j = 0; j < s.length(); j++)
			{
				if (s[j] >= 'A'&&s[j] <= 'Z')
				{
					res += NUM[s[j] - 'A'];
					cnt++;
					if (cnt == 3)
						res += "-";
				}
				else if (s[j] >= '0'&&s[j] <= '9')
				{
					res += s[j];
					cnt++;
					if (cnt == 3)
						res += "-";
				}
			}
			data.insert(res);
		}
		for (set<string>::iterator it = data.begin(); it != data.end(); it++)
			cout << *it << endl;
		cout << endl;
	}
	return 0;
}
#endif