/*

��Ȼ�мٱң� �����������ˣ�����ũ��Ĺ���ȴ�����ǰ���ûǮ��ô�����Ⱑ��nowcoder���ȥ�����⣬
�����������Ǯ���мٱң�������ϧnowcoder һ��С�İ��������һ���������ȥ�ˡ�
ֻ֪���ٱҵ���������ҵ�����Ҫ�ᣬ����һ����ƽ����ƽ�������������޸�Ӳ�ң���
��������ʱ����Ǹ��ɶ�ļٱ��ҳ�����

��������:
1��n��2^30,����0��������


�������:
���Ҫ�Ƽ���һ���ܰ��Ǹ��ٱ��ҳ�����
ʾ��1
����
3
12
0
���
1
3
*/
#include <iostream>
#include <vector>
using namespace std;
int find_fake(int num)
{
	if (num == 1)
		return 0;
	if (num <= 3)
		return 1;
	else
		return 1 + find_fake(num / 2);
}

int main()
{
	int N;
	while (cin >> N&&N)
	{
		int ans = 0;
		long long sum = 1;
		while (sum<N)
		{
			sum *= 3;
			ans++;
		}
		cout << ans << endl;
	}
	return 0;
}
/*


����һ��ȫ������������arr������һ��arr����С������ɺ͵ĸ�� 
1��arr�����зǿ��Ӽ��У���ÿ���Ӽ��ڵ�����Ԫ�ؼ���������ֺܶ��ֵ��������С�ļ�Ϊmin�����ļ�Ϊmax��
2��������[min,max]�ϣ������һЩ���������Ա�arrĳһ���Ӽ���ӵõ�����ô��Щ��������С���Ǹ�������arr����С������ɺͣ�
3��������[min,max]�ϣ�������е��������Ա�arr��ĳһ���Ӽ���ӵõ�����ômax+1��arr����С������ɺͣ� 
������ arr = {3,2,5} arr��minΪ2��maxΪ10��������[2,10]�ϣ�4�ǲ��ܱ��κ�һ���Ӽ���ӵõ���ֵ����С�ģ�
����4��arr����С������ɺͣ� arr = {3,2,4} arr��minΪ2��maxΪ9��������[2,9]�ϣ�8�ǲ��ܱ��κ�һ���Ӽ���ӵõ���ֵ����С�ģ�
����8��arr����С������ɺͣ� arr = {3,1,2} arr��minΪ1��maxΪ6��������[2,6]�ϣ��κ��������Ա�ĳһ���Ӽ���ӵõ���
����7��arr����С������ɺͣ� ��д��������arr����С������ɺ͡�
*/
int getFirstUnFormedNum(vector<int> arr, int len) {


	int sum = 0, min = arr[0];
	for (int i = 0; i < len; ++i)
	{
		sum += arr[i];
		if (arr[i] < min)
			min = arr[i];
	}
	vector<int> dp(sum + 1, 0);
	for (int i = 0; i < len; ++i)
	{
		for (int j = sum; j >= arr[i]; --j)
		{
			if (dp[j - arr[i]] + arr[i] > dp[j])
			{
				dp[j] = dp[j - arr[i]] + arr[i];
			}
		}
	}

	for (int i = min; i <= sum; ++i)
	{
		if (i != dp[i])
			return i;
	}
	return sum + 1;
}
};