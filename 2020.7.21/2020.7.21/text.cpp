/*
从C/C++转到Java的程序员，一开始最不习惯的就是变量命名方式的改变。
C语言风格使用下划线分隔多个单词，例如“hello_world”；
而Java则采用一种叫骆驼命名法的规则：除首个单词以外，所有单词的首字母大写，例如“helloWorld”。
请你帮可怜的程序员们自动转换变量名。

输入描述:
输入包含多组数据。

每组数据一行，包含一个C语言风格的变量名。每个变量名长度不超过100。


输出描述:
对应每一组数据，输出变量名相应的骆驼命名法。
示例1
输入
hello_world
nice_to_meet_you
输出
helloWorld
niceToMeetYou
*/
#include <iostream>
#include <string>
using namespace std;
void function()
{
	string str;
	while (cin >> str)
	{
		string::iterator it = str.begin();
		while (it != str.end())
		{
			if (*it == '_')
			{
				++it;
				*it -= 32;
				cout << *it ;
			}
			else
			{
				cout << *it;
			}
			it++;
		}
		cout << endl;
	}
}


/*
对字符串中的所有单词进行倒排。

说明：

1、构成单词的字符只有26个大写或小写英文字母；

2、非构成单词的字符均视为单词间隔符；

3、要求倒排后的单词间隔符以一个空格表示；如果原字符串中相邻单词间有多个间隔符时，
倒排转换后也只允许出现一个空格间隔符；

4、每个单词最长20个字母；


输入描述:
输入一行以空格来分隔的句子



输出描述:
输出句子的逆序

示例1
输入
I//am??a\\student
输出
student a am I
*/
#include <vector>
void function2()
{
	string str;
	while (getline(cin, str))
	{
		vector<string>svec;
		svec.clear();
		string temp = "";
		for (int i = 0; i<str.size(); ++i)
		{
			if (str[i] >= 'a' && str[i] <= 'z' || str[i] >= 'A' && str[i] <= 'Z')
				temp += str[i];
			else
			{
				if (temp.size()>0)
				{
					svec.push_back(temp);
					temp = "";
				}
			}
		}
		if (temp.size()>0)
			svec.push_back(temp);
		for (int i = svec.size() - 1; i>0; --i)
			cout << svec[i] << ' ';
		cout << svec[0] << endl;
	}
}
int main()
{
	function2();
	return 0;
}