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
		for (int i = 0; i <= str1.size(); i++)//i=0ʱ������ǰ�ߣ�i=str1.size()ʱ��������
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
		//ÿ��һ�����ݣ���֮ǰ��sum_max��һ�£���Ļ���˵˵��Ҫ���������
		if (sum > max)
		{
			max = sum;
		}
		//sum<0�ˣ�˵���϶��и��������ˣ������϶��������ȵ��Ǹ��������Ҫ��sum��գ���ʼ��һ���µ��ۼ�
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