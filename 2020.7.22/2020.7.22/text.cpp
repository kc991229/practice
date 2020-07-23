/*
nowcoder有两盒（A、B）乒乓球，有红双喜的、有亚力亚的……
现在他需要判别A盒是否包含了B盒中所有的种类，并且每种球的数量不少于B盒中的数量，该怎么办呢？

输入描述:
输入有多组数据。
每组数据包含两个字符串A、B，代表A盒与B盒中的乒乓球，每个乒乓球用一个大写字母表示，即相同类型的乒乓球为相同的大写字母。
字符串长度不大于10000。

输出描述:
每一组输入对应一行输出：如果B盒中所有球的类型在A中都有，并且每种球的数量都不大于A，则输出“Yes”；否则输出“No”。
示例1
输入
ABCDFYE CDE
ABCDGEAS CDECDE
输出
Yes
No
*/
#include <iostream>
#include <string>
using namespace std;
bool function1(string str1,string str2)
{
	int arr1[26] = { 0 };
	int arr2[26] = { 0 };
	for (auto s : str1)
	{
		arr1[s - 'A']++;
	}
	for (auto s : str2)
	{
		arr2[s - 'A']++;
	}
	for (int i = 0; i < 26; i++)
	{
		if (arr1[i] < arr2[i])
		{
			return false;
		}
	}
	return true;
}
int main()
{
	string str1, str2;
	while (cin >> str1 >> str2)
	{
		if (function1(str1, str2))
			cout << "Yes" << endl;
		else
			cout << "No" << endl;
	}
}