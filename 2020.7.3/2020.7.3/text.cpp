/*

居然有假币！ 现在猪肉涨了，但是农民的工资却不见涨啊，没钱怎么买猪肉啊。nowcoder这就去买猪肉，
结果找来的零钱中有假币！！！可惜nowcoder 一不小心把它混进了一堆真币里面去了。
只知道假币的重量比真币的质量要轻，给你一个天平（天平两端能容纳无限个硬币），
请用最快的时间把那个可恶的假币找出来。

输入描述:
1≤n≤2^30,输入0结束程序。


输出描述:
最多要称几次一定能把那个假币找出来？
示例1
输入
3
12
0
输出
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


给定一个全是正数的数组arr，定义一下arr的最小不可组成和的概念： 
1，arr的所有非空子集中，把每个子集内的所有元素加起来会出现很多的值，其中最小的记为min，最大的记为max；
2，在区间[min,max]上，如果有一些正数不可以被arr某一个子集相加得到，那么这些正数中最小的那个，就是arr的最小不可组成和；
3，在区间[min,max]上，如果所有的数都可以被arr的某一个子集相加得到，那么max+1是arr的最小不可组成和； 
举例： arr = {3,2,5} arr的min为2，max为10，在区间[2,10]上，4是不能被任何一个子集相加得到的值中最小的，
所以4是arr的最小不可组成和； arr = {3,2,4} arr的min为2，max为9，在区间[2,9]上，8是不能被任何一个子集相加得到的值中最小的，
所以8是arr的最小不可组成和； arr = {3,1,2} arr的min为1，max为6，在区间[2,6]上，任何数都可以被某一个子集相加得到，
所以7是arr的最小不可组成和； 请写函数返回arr的最小不可组成和。
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