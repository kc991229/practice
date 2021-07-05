#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool Parse_title(const string& all_str, string* res_str)
{
	//1.Ѱ��string�ڵ�<title> </title>���±�
	//2.�������±�Ϊ�磬֮��ľ��Ǳ���
	//3.�����������Ҫ���ص�string��
	size_t head = 0, tail = 0;
	head = all_str.find("<title>") + 7;
	tail = all_str.find("</title>");
	string tmp;
	while (head < tail)
	{
		tmp += all_str[head];
		head++;
	}
	*res_str = tmp;
	return true;
}
bool Parse_content(string& html, string* res_str)
{
	//1.ѭ����������string
	//2.�жϵ�ǰ�����Ƿ�Ϊ��ǩ����
	//3.��Ϊ��ǩȥ������Ϊ���ģ�����
	bool is_content = true;
	for (auto v : html)
	{
		if (is_content)//��ǰ�Ѿ�������
		{
			if (v == '<')
			{
				is_content = false;
				continue;
			}
			else
			{
				if (v == '\n')
				{
					v = ' ';
				}


				res_str->push_back(v);
			}
		}
		else  //��ǰΪ��ǩ����

		{
			if (v == '>')
			{
				cout << "1";
				//��ζ�ű�ǩ������
				is_content = true;
			}

		}
	}
	return true;
}
class Solution {
public:
	int removeDuplicates(vector<int>& nums)
	{
		if (nums.size() == 0)
			return 0;
		if (nums.size() == 1)
			return 1;
		vector<int>::iterator it1 = nums.begin();
		vector<int>::iterator it2 = nums.begin()++;
		while (it2 != nums.end())
		{
			if (*it1 == *it2)
			{
				nums.erase(it2);
				it2 = it1;
				it2++;
			}
			else
			{
				it1++, it2++;
			}
		}
		return nums.size();
	}
};
int main()
{
	vector<int> vc(5, 2);
	vector<int>::iterator it = vc.begin();
	auto its = vc.end();
	cout << *it << endl;
	cout << *its << endl;
	return 0;
}