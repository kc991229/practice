#include <iostream>
#include <string>
#include <vector>
using namespace std;
//��һ���Ź�������飬����n����������������������������һ�����ȵ���λ��
//���磬ԭ����Ϊ[1, 2, 3, 4, 5, 6]��������λ5��λ�ü������[6, 1, 2, 3, 4, 5], 
//���ڶ�����λ������飬��Ҫ����ĳ��Ԫ�ص�λ�á������һ�����Ӷ�Ϊlog������㷨����������
//����һ��int����A��Ϊ��λ������飬ͬʱ���������Сn����Ҫ���ҵ�Ԫ�ص�ֵx��
//�뷵��x��λ��(λ�ô��㿪ʼ)����֤������Ԫ�ػ��졣
//����������
//[6, 1, 2, 3, 4, 5], 6, 6
//���أ�0

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
			// �ұ�����x�������ұߵ�ֵ��˵����߰���x,��С��Χ��
			if (A[mid]<A[left] && x>A[right]) 
				right = mid - 1;
			else 
				left = mid + 1;
		}
		if (A[mid]>x)
		{
			// �������xС������ߵ�ֵ��˵���ұ߰���x,��С��Χ��
			if (A[mid]>A[left] && x<A[left]) 
				left = mid + 1;
			else 
				right = mid - 1;
		}
	}
	return -1;
}


//����һ���ַ�����������ַ����������ַ����ϣ����磺���� abcqwerabc �������acbwqer
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
