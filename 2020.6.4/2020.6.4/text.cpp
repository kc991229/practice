#include <iostream>
#include <string>
//题目：输入一个十进制的数num和一个需要转换的M进制的值，将该数转换为M进制并输出

//解题思路：该题目的难点在于对十进制以上情况的转换，此时加入了A,B,C,D,E,F
//我们其实可以转换思维，并不是非要以整形的方式去输出，可以利用字符串解决
//定义一个数组，每个下标对应其内容，例如arr[1]里存放1，arr[10]存放A
//对于进制的转换采用除以该进制取余法，这里采用字符串的好处也在于可以直接在字符串后面添加

int main()
{
	size_t num = 0, M = 0;
	char arr[] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B,', 'C', 'D', 'E', 'F' };
	std::cin >> num >> M;
	std::string str("");
	if (num == 0)
		str = '0';
	while (num)
	{
		if (num < 0)
		{
			num = -num;
			std::cout << "-";
		}
		str = arr[num%M]+str;
		num = num / M;
	}
	for (auto v : str)
	{
		std::cout << v;
	}
	return 0;
}