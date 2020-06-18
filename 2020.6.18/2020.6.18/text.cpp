/*
完全数（Perfect number），又称完美数或完备数，是一些特殊的自然数。它所有的真因子（即除了自身以外的约数）的和（即因子函数），恰好等于它本身。例如：28，1+2+4+7+14=28。给定数计算n以内完全数的个数。计算范围, 0 < n <= 500000
返回n以内完全数的个数。异常情况返回-1。

输入描述：
输入一个数字
输出描述：
输出完全数的个数
示例1:
输入
1000
输出
3
*/

#if 0
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int num = 0;
	while (cin >> num)
	{

		int count = 0;  //用于计数
		int k = 1;
		//必须是1，如果num为1 正好符合题意 不走循环，直接输出count = 0;
		//如果是0 的话， 不会进入for循环，但是和sum一样都等于0 count计数会++，
		//将0算进完全数中去
		while (k < num)
		{
			int sum = 0;
			for (int i = 1; i < k; i++) //不包括自身 所以i取不到k
			{

				if (k % i == 0)
					sum += i;

			}
			if (sum == k)
				count++;
			k++;
		}
		cout << count << endl;
	}

}
#endif

/*
扑克牌游戏大家应该都比较熟悉了，一副牌由54张组成，含3~A、2各4张，小王1张，大王1张。
牌面从小到大用如下字符和字符串表示（其中，小写joker表示小王，大写JOKER表示大王）：
3 4 5 6 7 8 9 10 J Q K A 2 joker JOKER
输入两手牌，两手牌之间用"-"连接，每手牌的每张牌以空格分隔，"-"两边没有空格，如：4 4 4 4-joker JOKER。
请比较两手牌大小，输出较大的牌，如果不存在比较关系则输出ERROR。
基本规则：
（1）输入每手牌可能是个子、对子、顺子（连续5张）、三个、炸弹（四个）和对王中的一种，不存在其他情况，
由输入保证两手牌都是合法的，顺子已经从小到大排列；
（2）除了炸弹和对王可以和所有牌比较之外，其他类型的牌只能跟相同类型的存在比较关系
（如，对子跟对子比较，三个跟三个比较），不考虑拆牌情况（如：将对子拆分成个子）；
（3）大小规则跟大家平时了解的常见规则相同，个子、对子、三个比较牌面大小；顺子比较最小牌大小；
炸弹大于前面所有的牌，炸弹之间比较牌面大小；对王是最大的牌；
（4）输入的两手牌不会出现相等的情况。
*/
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
class compare
{
public:
	string GetBig(const string str)
	{
		string result;
		string s1, s2;
		string comper("3 4 5 6 7 8 9 10 J Q K A 2 joker JOKER");
		//当有大小王时候，一定是大小王最大
		if (str.find("joker JOKER")!=string::npos)
		{
			result = "joker JOKER";
			return result;
		}

		//将两副牌分开,存于不同的string中
		int mid = str.find('-');
		s1 = str.substr(0, mid);
		s2 = str.substr(mid + 1);

		//得到两副牌的' '数量，以此判断是否为相同类型。注意不能使用长度判断，会因为joker产生bug
		int s1_count = count(s1.begin(), s1.end(), ' ');
		int s2_count = count(s2.begin(), s2.end(), ' ');

		//两副牌为相同的类型，比较最小的大小即可
		if (s1_count == s2_count)
		{
			//得到最小的的牌
			string s1_first = s1.substr(0, s1.find(' '));
			string s2_first = s2.substr(0, s2.find(' '));
			
			if (comper.find(s1_first) < comper.find(s2_first))
			{
				result = s2;
				return result;
			}
			else
			{
				result = s1;
				return result;
			}
		}

		//两副牌不相同，有炸弹或者不符合条件
		else
		{
			if (s1_count == 3 && s1[0] == s1[2] && s1[2]== s1[4] && s1[4]== s1[6])
			{
				result = s1;
			}
			else if (s2_count == 3 && s2[0] == s2[2] && s1[2] == s2[4] && s2[4] == s2[6])
			{
				result = s2;
			}
			else
				result = "ERROR";
			return result;
		}
	}
};
int main()
{
	string str;
	compare c;
	getline(cin, str);
	str = c.GetBig(str);
	cout << str;
	return 0;
}