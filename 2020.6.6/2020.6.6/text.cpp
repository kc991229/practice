#include <iostream>
#include <string>
using namespace std;

//��һ���ַ���ת����һ������(ʵ��Integer.valueOf(string)�Ĺ��ܣ�����string����������Ҫ��ʱ����0)��
//Ҫ����ʹ���ַ���ת�������Ŀ⺯���� ��ֵΪ0�����ַ�������һ���Ϸ�����ֵ�򷵻�0��

//����˼·����������ASCLL�����ֵ������Կ�ʼλ�ķ��Ž��к����ж�
int StrToInt(string str) 
{
	if (str.size() == 0)//�ж��Ƿ�Ϊ���ַ���
		return 0;
	size_t flag = 0;//�������ű�־λ
	size_t start = 0;//��������±�
	size_t num = 0;//�����洢����ֵ

	//�жϷ���λ
	if (str[0] == '+')
	{
		start++;
		flag = 1;
	}
	if (str[0] == '-')
	{
		start++;//�жϺ�Ҫ���±����һλ
		flag = -1;
	}

	for (start; start < str.size(); start++)
	{
		if (str[start] >= '0'&&start <= '9')
			num = num * 10 + str[start] - '0';//���ù�ʽ��ԭ����10�����ڵ���
		else
			return 0;//���ֲ������������ֱ�ӷ���0
	}
	return num;
}
int main()
{
	std::string str("1234");

	int i=StrToInt( str);
	cout << i;
	return 0;
}