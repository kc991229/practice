#if 0
/*
һ�����������Էֽ��һ����������Ļ�������36=2*2*3*3��������2��3�������ӡ�NowCoder������о����Ӹ����ķֲ����ɣ����ڸ���һϵ������������ϣ���㿪��һ���������ÿ�������������Ӹ�����

����:
��������������ݡ�
ÿ�����ݽ���һ������n (2��n��100000)��

���:
��Ӧÿ����������������Ӹ�����ÿ�����ռһ�С�
ʾ��1
����:
30
26
20
���
3
2
2
*/
#include <iostream>
#include <math.h>
#include <set>
using namespace std;
set<int> s;
bool judge_prime(int num)//�ж��������Ƿ���1���Ƿ���0
{
	if (num == 2)
		return true;
	for (int i = 2; i <= sqrt((double)num); i++)
	{
		if (num%i == 0)
			return false;
	}
	return true;
}
void Get_Fac_Count(int num)
{
	if (judge_prime(num))
	{
		s.insert(num);
		return;
	}
		
	int i = 0, j = 0;
	for (i = 2; i <= sqrt((double)num); i++)
	{
		if (num%i == 0)
		{
			s.insert(i);
			Get_Fac_Count(num / i);
			return;
		}
	}
}
int main()
{
	int i = 0;
	while (cin >> i)
	{
		if (judge_prime(i))
		{
			cout << "1" << endl;
			continue;
		}
		s.clear();
		Get_Fac_Count(i);
		cout << s.size() << endl;
	}
}
#endif
#if 1
/*
NowCoder�����ڳ���Σ�պ���ı�������Ϊ�����棬���״η��������룬���ھ��ӵ���Ϣ���ݡ�
�������Ǿ����е�һ�����٣���Ҫ�ѷ���������Ϣ�������������
������Ľ�����
��Ϣ���ܵİ취�ǣ�����Ϣԭ���е�ÿ����ĸ���ֱ��ø���ĸ֮��ĵ�5����ĸ�滻
���磺��Ϣԭ���е�ÿ����ĸA ���ֱ��滻����ĸF���������ַ����䣬������Ϣԭ�ĵ�������ĸ���Ǵ�д�ġ�
�����е���ĸ��ԭ���е���ĸ��Ӧ��ϵ���¡�
������ĸ��A B C D E F G H I J K L M N O P Q R S T U V W X Y Z
ԭ����ĸ��V W X Y Z A B C D E F G H I J K L M N O P Q R S T U

��������:
��������������ݣ�ÿ������һ�У�Ϊ�յ������ġ�
���Ľ��пո�ʹ�д��ĸ��ɡ�


�������:
��Ӧÿһ�����ݣ�������ܺ�����ġ�
*/
#include <iostream>
#include <string>
using namespace std;
int main()
{
	string str;
	while (getline(cin,str))
	{
		string::iterator it = str.begin();
		for (; it != str.end(); it++)
		{
			if (*it >= 'F' && *it <= 'Z')
			{
				*it -= 5;
			}
			else if (*it >= 'A' && *it <= 'E')
			{
				*it += 21;
			}
			else
				*it = ' ';
		}
		for (auto v : str)
			cout << v;
		cout << endl;
	}
	return 0;
}
#endif