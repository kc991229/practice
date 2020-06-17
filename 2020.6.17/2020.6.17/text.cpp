#include <iostream>
#include <algorithm>
#include <climits>
#include <vector>
using namespace std;

/*
在地下室里放着n种颜色的手套，手套分左右手，但是每种颜色的左右手手套个数不一定相同。
A先生现在要出门，所以他要去地下室选手套。但是昏暗的灯光让他无法分辨手套的颜色，只能分辨出左右手。
所以他会多拿一些手套，然后选出一双颜色相同的左右手手套。现在的问题是，他至少要拿多少只手套(左手加右手)
，才能保证一定能选出一双颜色相同的手套。

给定颜色种数n(1≤n≤13),同时给定两个长度为n的数组left,right,分别代表每种颜色左右手手套的数量。
数据保证左右的手套总数均不超过26，且一定存在至少一种合法方案。

测试样例：
4,[0,7,1,6],[1,5,0,6]
返回：
10(解释：可以左手手套取2只，右手手套取8只)
*/


/*首先，要保证拿出至少一对匹配的手套
*	我们保证所有颜色都拿一只(在左右手套中选择数量相对较少的来拿所有颜色)
*		只需要用该边手套总数减去最少数量+1即可
*	然后另一边手套只需要拿一只就可以保证匹配
*其次，考虑某个颜色一边数量为0的情况
*	要把另一边相应颜色的手套数加进去*/
class Gloves {
public:
	int findMinimum(int n, vector<int> left, vector<int> right)
	{
		int count = 0, left_count = 0, right_count = 0, left_min = INT_MAX, right_min = INT_MAX;
		for (int i = 0; i < n; ++i)
		{
			if (left[i] == 0 || right[i] == 0) //如果某一边对应颜色数量为0，则加上另一边的数量
				count += left[i] + right[i];
			else
			{
				left_count += left[i]; //统计左边手套数
				right_count += right[i]; //统计右边手套数
				left_min = min(left_min, left[i]); //找出左边最小数量
				right_min = min(right_min, right[i]); //找出右边最小数量
			}
		}

		return count + min(left_count - left_min + 1, right_count - right_min + 1) + 1;
	}
}



