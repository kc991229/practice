#if 0
/*
有这样一道智力题：“某商店规定：三个空汽水瓶可以换一瓶汽水。小张手上有十个空汽水瓶，
她最多可以换多少瓶汽水喝？”答案是5瓶，方法如下：先用9个空瓶子换3瓶汽水，喝掉3瓶满的，
喝完以后4个空瓶子，用3个再换一瓶，喝掉这瓶满的，这时候剩2个空瓶子。
然后你让老板先借给你一瓶汽水，喝掉这瓶满的，喝完以后用3个空瓶子换一瓶满的还给老板。
如果小张手上有n个空汽水瓶，最多可以换多少瓶汽水喝？
*/
#include <iostream>
using namespace std;

int getNum(int count)
{
	int num = 0;
	if (count <= 1)
		return 0;
	if (count == 2)
		return 1;
	return count / 3 + getNum(count / 3 + count % 3);
}
int main()
{
	int arr[11] = { -1 };
	int i, j;
	for (i = 0; i<10; i++)
	{
		cin >> arr[i];
		if (arr[i] == 0) //i的数量为数据个数
			break;
	}
	for (int j = 0; j<i; j++)
	{
		cout << getNum(arr[j]) << endl;
	}
	return 0;
}
#endif

//查找两个字符串a,b中的最长公共子串 
/*
输入例子：
abcdefghijklmnop
abcsafjklmnopqrstuvw

输出例子:
jklmnop
*/
#include <iostream>
#include <string>
using namespace std;
void function()
{
	string str1, str2;
	string temp1, temp2;
	while (cin >> str1 >> str2)
	{
		string::iterator it1 = str1.begin();
		string::iterator it2 = str2.begin();
	}
}