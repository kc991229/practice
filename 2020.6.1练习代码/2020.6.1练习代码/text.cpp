#include<iostream>
#include<string>
#include "function.h"
void text1()
{
	std::string str1;
	std::string str2;
	std::getline(std::cin, str1);
	std::getline(std::cin, str2);
	delete_str(str1, str2);
	for (auto ch : str1)
	{
		std::cout << ch;
	}
}
void text2()
{
	size_t i = 0;
	std::cin >> i;
	std::cout<<max_value(i);
}
int main()
{
	//text1();
	text2();
	return 0;
}