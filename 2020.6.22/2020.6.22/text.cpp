#if 0
/*
������һ�������⣺��ĳ�̵�涨����������ˮƿ���Ի�һƿ��ˮ��С��������ʮ������ˮƿ��
�������Ի�����ƿ��ˮ�ȣ�������5ƿ���������£�����9����ƿ�ӻ�3ƿ��ˮ���ȵ�3ƿ���ģ�
�����Ժ�4����ƿ�ӣ���3���ٻ�һƿ���ȵ���ƿ���ģ���ʱ��ʣ2����ƿ�ӡ�
Ȼ�������ϰ��Ƚ����һƿ��ˮ���ȵ���ƿ���ģ������Ժ���3����ƿ�ӻ�һƿ���Ļ����ϰ塣
���С��������n������ˮƿ�������Ի�����ƿ��ˮ�ȣ�
*/
#include <iostream>
using namespace std;

int getNum(int count)
{
	int num = 0;
	if (count <= 1)
		return 0;
	if (count == 2)
		return 1;
	return count / 3 + getNum(count / 3 + count % 3);
}
int main()
{
	int arr[11] = { -1 };
	int i, j;
	for (i = 0; i<10; i++)
	{
		cin >> arr[i];
		if (arr[i] == 0) //i������Ϊ���ݸ���
			break;
	}
	for (int j = 0; j<i; j++)
	{
		cout << getNum(arr[j]) << endl;
	}
	return 0;
}
#endif

//���������ַ���a,b�е�������Ӵ� 
/*
�������ӣ�
abcdefghijklmnop
abcsafjklmnopqrstuvw

�������:
jklmnop
*/
#include <iostream>
#include <string>
using namespace std;
void function()
{
	string str1, str2;
	string temp1, temp2;
	while (cin >> str1 >> str2)
	{
		string::iterator it1 = str1.begin();
		string::iterator it2 = str2.begin();
	}
}