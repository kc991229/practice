#include <iostream>
#include <vector>
using namespace std;
/*

����һ�����������һ���㷨�����Ͻ�(mat[0][0])��ʼ��˳ʱ���ӡ����Ԫ�ء�

����int����mat,�Լ�����ά��nxm���뷵��һ�����飬�����е�Ԫ��Ϊ����Ԫ�ص�˳ʱ�������

����������
[[1,2],[3,4]],2,2
���أ�[1,2,4,3]
*/
class Printer 
{
public:
	vector<int> clockwisePrint(vector<vector<int> > mat, int n, int m)
	{
		vector<int>ans;
		int order[4][2] = { { 0, 1 }, { 1, 0 }, { 0, -1 }, { -1, 0 } };//��������
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
����һ������ΪN(N>1)����������A�����Խ�A���ֳ������������֣��󲿷�A[0..K]���Ҳ���A[K+1..N-1]��
K����ȡֵ�ķ�Χ��[0,N-2]������ô�໮�ַ����У��󲿷��е����ֵ��ȥ�Ҳ������ֵ�ľ���ֵ������Ƕ��٣�

������������A������Ĵ�Сn���뷵����Ŀ����Ĵ𰸡�

����������
[2,7,3,1,1],5
���أ�6
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
