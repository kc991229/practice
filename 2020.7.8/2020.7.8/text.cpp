/*
һ�黨������������Щͼ��������һ��ֱ�ӿ��õ�С����������Ҳ��һЩͼ�������ڸ����Ļ�������С������
����һ���ܴӻ������о����ܼ�������С�������أ�

��������:
ÿ�����ݰ��������ַ���s,t���ֱ��ǳɶԳ��ֵĻ�������С�������䲼�������ÿɼ�ASCII�ַ���ʾ�ģ�
�ɼ���ASCII�ַ��ж��ٸ��������Ļ���Ҳ�ж����ֻ�������������С�������ᳬ��1000���ַ�����

�������:
��Ӧÿ�����룬����ܴӻ��Ʋ��м��������С�������������һ�鶼û�У��Ǿ����0��ÿ�����ռһ�С�
ʾ��1
����
abcde a3
aaaaaa aa
���
0
3
*/
#include <iostream>
#include <string>
using namespace std;

void function()
{
	string s, t;
	while (cin >> s >> t)
	{
		int count = 0;
		int pos = 0;
		while (s.find(t, pos) != string::npos)
		{
			count++;
			pos = s.find(t, pos) + t.size();
		}
		cout << count << endl;
	}
}

/*
NowCoder����һ����͵꣬��ҵ�Ŀ��˶��и���ֵ��ã�����ֻҪ����ҵ�Թ�һ����ͣ��ͻ�ÿ�춼������
���ң�����������ҵ����������ͺ󣬽�����ÿ�춼���һλ������һ����Ʒ����
���ǣ���ҵ�Ŀ��˴����һ���˷�չ�ɺƺƵ����ɰ���ǧ�ˣ�1��1��2��3��5����
���ڣ�NowCoder�������æͳ��һ�£�ĳһ��ʱ�䷶Χ�����ܹ��������ٷ���ͣ�����ÿλ����ֻ��һ����ͣ���

��������:
�������ݰ������顣
ÿ�����ݰ�����������from��to(1��from��to��80)���ֱ������ĵ�from��͵�to�졣

�������:
��Ӧÿһ�����룬�����from��to��Щ�������from��to���죩����Ҫ�����ٷ���͡�
*/
#include <iostream>
int Fibonacci(int num)
{
	if (num == 1 || num == 2)
		return 1;
	int count1 = 0;
	int a = 1, b = 1;
	while (num >= 3)
	{
		count1 = a + b;
		a = b;
		b = count1;
		num--;
	}
	return count1;
}
void function1()
{
	int from, to;
	while (cin >> from >> to)
	{
		int count = 0;
		while (from <= to)
		{
			count += Fibonacci(from);
			from++;
		}
		cout << count << endl;
	}
}
int main()
{
	function1();
	return 0;
}