#include <iostream>
using namespace std;

/*有一棵无穷大的满二叉树，其结点按根结点一层一层地从左往右依次编号，
根结点编号为1。现在有两个结点 a，b。请设计一个算法，求出a和b点的最近公共祖先的编号。
给定两个int a,b。为给定结点的编号。*/
class LCA {
public:
	int getLCA(int a, int b) {
		if (a>b)
			swap(a, b);
		while (a != b)
		{
			if (b>a)
			{
				while (b>a)
				{
					b = b / 2;
				}
			}
			else if (b<a)
			{
				while (b<a)
					a = a / 2;
			}
		}
		return a;
	}
};

/*
求一个byte数字对应的二进制数字中1的最大连续数，例如3的二进制为00000011，最大连续2个1
输入: 一个byte型的数字
*/

size_t get_num_1(size_t byte)
{
	size_t max = 0, temp = 0;
	while (byte)
	{
		while (byte & 1)
		{
			temp++;
			byte = byte >> 1;
		}
		if (max < temp)
		{
			max = temp;
			temp = 0;
		}
		else
			temp = 0;
		byte = byte >> 1;
	}
	return max;
}
int main()
{
	size_t byte = 0;
	cin >> byte;
	cout << get_num_1(byte);
	return 0;
}