#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
//��Ŀ������һ���ַ�����������ַ�����������ִ������磺abc123de45fg123456  -�������123456
void print_long_num(const std:: string _str)
{
	std::string str(_str);
	size_t num = 0;  //������¼���ִ��ĳ���
	size_t num_temp = 0;
	std::string::iterator head;  //������¼���ִ��ĵ�ַ
	std::string::iterator p_temp;
	std::string::iterator it = str.begin();  //����һ���������������ַ���
	str += 'k';//�ַ���ĩ����һ���ַ�����ֹ����Խ��
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
			if (num_temp > num)//��ǰ���ִ��Ĵ�С���ڼ�¼�Ĵ�С�����滻
			{
				num = num_temp;
				head = p_temp;
				num_temp = 0;
			}
			else{
				num_temp = 0;//Ҫ�ǵ���գ�������bug
			}
		}
		it++;
	}
	for (size_t i = 0; i < num; i++)//ѭ����ӡ
	{
		std::cout << *head;
		head++;
	}
}

//��Ŀ������һ�����飬����������ĳ���������������С��һ�룬��õ����������޷���0
//����int arr[]={0,1,2,2,2,2,3};  2���������������Сһ�룬����2

//���⣺������������������������������һ������λ�������������򣬺�����λ�������ж��Ƿ�����
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