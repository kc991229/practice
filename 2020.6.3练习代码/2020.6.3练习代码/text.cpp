#include "function.h"

void text1()
{
	std::string str;
	std::getline(std::cin, str);
	print_long_num(str);
}
void text2()
{
	std::vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	int num;
	majorityElement(v);
}
int main()
{
	text1();
	text2();
}
