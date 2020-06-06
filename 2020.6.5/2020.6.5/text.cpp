#include<iostream>
#include<string>
using namespace std;
bool judge(string str)
{
	int begin = 0;
	int end = str.size() - 1;
	while (begin <= end)
	{
		if (str[begin] == str[end])
		{
			begin++;
			end--;
		}
		else
			break;
	}
	if (begin<end)
		return false;
	else
		return true;
}

int main()
{
	string str1, str2;
	while (cin >> str1&&cin >> str2)
	{
		int cnt = 0;
		for (int i = 0; i <= str1.size(); i++)//i=0时插入最前边，i=str1.size()时插入最后边
		{
			string str3 = str1;
			str3.insert(i, str2);
			if (judge(str3))
				cnt++;
		}
		cout << cnt << endl;
	}

}

#if 0
#include <iostream>
#include <vector>
using namespace std;
int max_sum()
{
	int N;
	cin >> N;
	vector<int> v(N);

	for (int i = 0; i < N; i++)
	{
		cin >> v[i];
	}

	int max = v[0];
	int sum = 0;
	for (int i = 0; i < v.size(); i++)
	{
		sum += v[i];
		//每加一个数据，和之前的sum_max比一下，大的话就说说明要加上这个数
		if (sum > max)
		{
			max = sum;
		}
		//sum<0了，说明肯定有负数出现了，负数肯定是拉后腿的那个数，因此要将sum清空，开始下一次新的累计
		if (sum < 0)
		{
			sum = 0;
		}
	}
	return max;
}
int main()
{
	cout << max_sum();
	return 0;
}
#endif