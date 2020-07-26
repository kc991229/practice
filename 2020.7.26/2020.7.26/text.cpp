#include <iostream>
#include <vector>
using namespace std;
/*

对于一个矩阵，请设计一个算法从左上角(mat[0][0])开始，顺时针打印矩阵元素。

给定int矩阵mat,以及它的维数nxm，请返回一个数组，数组中的元素为矩阵元素的顺时针输出。

测试样例：
[[1,2],[3,4]],2,2
返回：[1,2,4,3]
*/
class Printer 
{
public:
	vector<int> clockwisePrint(vector<vector<int> > mat, int n, int m)
	{
		vector<int>ans;
		int order[4][2] = { { 0, 1 }, { 1, 0 }, { 0, -1 }, { -1, 0 } };//方向数组
		int i = 0, j = -1, start = 0;
		while (true) 
		{
			int a = i + order[start][0], b = j + order[start][1];
			if (!(0 <= a&&a<n) || !(0 <= b&&b<m) || mat[a][b] == INT_MAX)
				start = (start + 1) % 4;
			i = i + order[start][0], j = j + order[start][1];
			ans.push_back(mat[i][j]);
			mat[i][j] = INT_MAX;
			if (ans.size() == n*m)
				break;
		}
		return ans;
	}
};

/*
给定一个长度为N(N>1)的整型数组A，可以将A划分成左右两个部分，左部分A[0..K]，右部分A[K+1..N-1]，
K可以取值的范围是[0,N-2]。求这么多划分方案中，左部分中的最大值减去右部分最大值的绝对值，最大是多少？

给定整数数组A和数组的大小n，请返回题目所求的答案。

测试样例：
[2,7,3,1,1],5
返回：6
*/
class MaxGap 
{
public:
	int findMaxGap(vector<int> A, int n) 
	{
		int max = 0;
		int pos = 0;
		for (int i = 0; i < n; i++)
		if (max < A[i]){
			max = A[i];
			pos = i;
		}
		if (pos == 0)
			return A[0] - A[n - 1];
		if (pos == n - 1)
			return A[n - 1] - A[0];
		int left = (A[pos] - A[0]);
		int right = (A[pos] - A[n - 1]);
		return left > right ? left : right;
	}
};
