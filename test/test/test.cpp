#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool Parse_title(const string& all_str, string* res_str)
{
	//1.寻找string内的<title> </title>的下标
	//2.以两个下标为界，之间的就是标题
	//3.将标题填充入要返回的string中
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
	//1.循环遍历整个string
	//2.判断当前内容是否为标签内容
	//3.若为标签去除，若为正文，保存
	bool is_content = true;
	for (auto v : html)
	{
		if (is_content)//当前已经是正文
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
		else  //当前为标签内容

		{
			if (v == '>')
			{
				cout << "1";
				//意味着标签结束了
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