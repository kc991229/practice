#include <iostream>
#include <string>
#include <vector>
using namespace std;
//有一个排过序的数组，包含n个整数，但是这个数组向左进行了一定长度的移位，
//例如，原数组为[1, 2, 3, 4, 5, 6]，向左移位5个位置即变成了[6, 1, 2, 3, 4, 5], 
//现在对于移位后的数组，需要查找某个元素的位置。请设计一个复杂度为log级别的算法完成这个任务。
//给定一个int数组A，为移位后的数组，同时给定数组大小n和需要查找的元素的值x，
//请返回x的位置(位置从零开始)。保证数组中元素互异。
//测试样例：
//[6, 1, 2, 3, 4, 5], 6, 6
//返回：0

int findElement(vector<int> A, int n, int x) 
{
	int left = 0, right = n - 1;
	while (left <= right)
	{
		int mid = (right + left) / 2;
		if (A[mid] == x)
			return mid;
		if (A[mid]<x)
		{
			// 右边有序，x大于最右边的值，说明左边包含x,缩小范围。
			if (A[mid]<A[left] && x>A[right]) 
				right = mid - 1;
			else 
				left = mid + 1;
		}
		if (A[mid]>x)
		{
			// 左边有序，x小于最左边的值，说明右边包含x,缩小范围。
			if (A[mid]>A[left] && x<A[left]) 
				left = mid + 1;
			else 
				right = mid - 1;
		}
	}
	return -1;
}


//输入一个字符串，求出该字符串包含的字符集合，例如：输入 abcqwerabc ，输出，acbwqer
void function()
{
	string str_;
	getline(cin, str_);
	char arr[256] = { 0 };
	for (auto v : str_)
	{
		arr[v]++;
	}
	for (auto v : str_)
	{
		if (arr[v] != -1)
		{
			cout << v;
			arr[v] = -1;
		}
	}
}

int main()
{
	function();
	return 0;
}
