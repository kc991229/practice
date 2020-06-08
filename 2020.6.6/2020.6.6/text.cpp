#include <iostream>
#include <string>
using namespace std;

//将一个字符串转换成一个整数(实现Integer.valueOf(string)的功能，但是string不符合数字要求时返回0)，
//要求不能使用字符串转换整数的库函数。 数值为0或者字符串不是一个合法的数值则返回0。

//解题思路：巧妙运用ASCLL码的码值，再针对开始位的符号进行合理判断
int StrToInt(string str) 
{
	if (str.size() == 0)//判断是否为空字符串
		return 0;
	size_t flag = 0;//正负符号标志位
	size_t start = 0;//用来标记下标
	size_t num = 0;//用来存储返回值

	//判断符号位
	if (str[0] == '+')
	{
		start++;
		flag = 1;
	}
	if (str[0] == '-')
	{
		start++;//判断后要将下标后移一位
		flag = -1;
	}

	for (start; start < str.size(); start++)
	{
		if (str[start] >= '0'&&start <= '9')
			num = num * 10 + str[start] - '0';//套用公式，原数乘10加现在的数
		else
			return 0;//出现不满足的条件，直接返回0
	}
	return num;
}
int main()
{
	std::string str("1234");

	int i=StrToInt( str);
	cout << i;
	return 0;
}