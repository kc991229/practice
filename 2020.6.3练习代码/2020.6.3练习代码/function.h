#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
//题目：输入一个字符串，输出该字符串中最长的数字串。例如：abc123de45fg123456  -》输出：123456
void print_long_num(const std:: string _str)
{
	std::string str(_str);
	size_t num = 0;  //用来记录数字串的长度
	size_t num_temp = 0;
	std::string::iterator head;  //用来记录数字串的地址
	std::string::iterator p_temp;
	std::string::iterator it = str.begin();  //定义一个迭代器，遍历字符串
	str += 'k';//字符串末增加一个字符，防止访问越界
	while (it != str.end())
	{
		if (*it >= '0'&& *it <= '9')
		{
			p_temp = it;
			while (*it >= '0'&& *it <= '9')
			{
				num_temp++;
				it++;
			}
			if (num_temp > num)//当前数字串的大小大于记录的大小，则替换
			{
				num = num_temp;
				head = p_temp;
				num_temp = 0;
			}
			else{
				num_temp = 0;//要记得清空，否则会出bug
			}
		}
		it++;
	}
	for (size_t i = 0; i < num; i++)//循环打印
	{
		std::cout << *head;
		head++;
	}
}

//题目：输入一个数组，若数组中有某数个数大于数组大小的一半，则得到该数，若无返回0
//例如int arr[]={0,1,2,2,2,2,3};  2的数量大于数组大小一半，返回2

//解题：如果有满足条件的数，该数在排序后一定是中位数，可以先排序，后找中位数，再判断是否满足
size_t majorityElement(const std::vector<int>& nums)
{
	std::vector<int> v(nums);
	std::sort(v.begin(), v.end());
	size_t midnum = v[v.size() / 2];
	int temp = 0;
	for (auto x : v)
	{
		if (x == midnum)
			temp++;
		if (temp > v.size() / 2)
			return midnum;
	}
	return 0;
}