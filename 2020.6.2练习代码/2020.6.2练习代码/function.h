#include <iostream>
#include <string>
//��һ�仰���е��ã���㲻���á����磺I like bejing.   ->   bejing. like I
void resever(std::string::iterator s1, std::string::iterator s2)
{
	while (s1 < s2)
	{
		std::swap(*s1, *s2);
		s1++;
		s2--;
	}
}
void resever_str()
{
	std::string str;
	std::getline(std::cin, str);
	resever(str.begin(), str.end() - 1);
	std::string::iterator head = str.begin();
	std::string::iterator tail = str.begin()+1;
	while (tail !=str.end())
	{
		while (*tail == ' ')
		{
			resever(head, tail - 1);
			head = tail+1;
			tail++;
			continue;
		}
		tail++;
		
	}
	resever(head, tail - 1);
	for (auto v : str)
	{
		std::cout << v;
	}
}
//ţţ��������������Ϊһ��������һ��������������, ��������������Ƿǵ������߷ǵݼ�����ġ�ţţ��һ������Ϊn����������A, ��������һ�������ǰ�����A��Ϊ���ɶ�����������, ţţ��֪�������ٿ��԰���������Ϊ��������������.
//��������ʾ, ţţ���԰�����A����Ϊ[1, 2, 3]��[2, 2, 1]��������������, ������Ҫ����Ϊ2������������, �������2
//�������� :
//����ĵ�һ��Ϊһ��������n(1 �� n �� 10 ^ 5) �ڶ��а���n������A_i(1 �� A_i �� 10 ^ 9), ��ʾ����A��ÿ�����֡�
//������� :
//���һ��������ʾţţ���Խ�A���ٻ���Ϊ���ٶ�����������

#include<vector>
using namespace std;
int NUINIU_sort()
{
	int i = 0;
	int count = 0;
	int n;
	vector<int> vres;
	cin >> n;
	vres.resize(n + 1);
	for (int i = 0; i < n; i++)
	{
		cin >> vres[i];
	}
	while (i < n)
	{
		if (vres[i] < vres[i + 1])
		{
			while (i < n && vres[i] < vres[i + 1])
			{
				i++;
			}
			i++;
			count++;
		}
		else if (i < n && vres[i] == vres[i + 1])
		{
			i++;
		}

		else if (vres[i] > vres[i + 1])
		{
			while (i < n && vres[i] > vres[i + 1])
			{
				i++;
			}
			i++;
			count++;
		}
	}
	return count;
}


