/*
��C/C++ת��Java�ĳ���Ա��һ��ʼ�ϰ�ߵľ��Ǳ���������ʽ�ĸı䡣
C���Է��ʹ���»��߷ָ�������ʣ����硰hello_world����
��Java�����һ�ֽ������������Ĺ��򣺳��׸��������⣬���е��ʵ�����ĸ��д�����硰helloWorld����
���������ĳ���Ա���Զ�ת����������

��������:
��������������ݡ�

ÿ������һ�У�����һ��C���Է��ı�������ÿ�����������Ȳ�����100��


�������:
��Ӧÿһ�����ݣ������������Ӧ��������������
ʾ��1
����
hello_world
nice_to_meet_you
���
helloWorld
niceToMeetYou
*/
#include <iostream>
#include <string>
using namespace std;
void function()
{
	string str;
	while (cin >> str)
	{
		string::iterator it = str.begin();
		while (it != str.end())
		{
			if (*it == '_')
			{
				++it;
				*it -= 32;
				cout << *it ;
			}
			else
			{
				cout << *it;
			}
			it++;
		}
		cout << endl;
	}
}


/*
���ַ����е����е��ʽ��е��š�

˵����

1�����ɵ��ʵ��ַ�ֻ��26����д��СдӢ����ĸ��

2���ǹ��ɵ��ʵ��ַ�����Ϊ���ʼ������

3��Ҫ���ź�ĵ��ʼ������һ���ո��ʾ�����ԭ�ַ��������ڵ��ʼ��ж�������ʱ��
����ת����Ҳֻ�������һ���ո�������

4��ÿ�������20����ĸ��


��������:
����һ���Կո����ָ��ľ���



�������:
������ӵ�����

ʾ��1
����
I//am??a\\student
���
student a am I
*/
#include <vector>
void function2()
{
	string str;
	while (getline(cin, str))
	{
		vector<string>svec;
		svec.clear();
		string temp = "";
		for (int i = 0; i<str.size(); ++i)
		{
			if (str[i] >= 'a' && str[i] <= 'z' || str[i] >= 'A' && str[i] <= 'Z')
				temp += str[i];
			else
			{
				if (temp.size()>0)
				{
					svec.push_back(temp);
					temp = "";
				}
			}
		}
		if (temp.size()>0)
			svec.push_back(temp);
		for (int i = svec.size() - 1; i>0; --i)
			cout << svec[i] << ' ';
		cout << svec[0] << endl;
	}
}
int main()
{
	function2();
	return 0;
}