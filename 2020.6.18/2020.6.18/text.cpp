/*
��ȫ����Perfect number�����ֳ����������걸������һЩ�������Ȼ���������е������ӣ����������������Լ�����ĺͣ������Ӻ�������ǡ�õ������������磺28��1+2+4+7+14=28������������n������ȫ���ĸ��������㷶Χ, 0 < n <= 500000
����n������ȫ���ĸ������쳣�������-1��

����������
����һ������
���������
�����ȫ���ĸ���
ʾ��1:
����
1000
���
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

		int count = 0;  //���ڼ���
		int k = 1;
		//������1�����numΪ1 ���÷������� ����ѭ����ֱ�����count = 0;
		//�����0 �Ļ��� �������forѭ�������Ǻ�sumһ��������0 count������++��
		//��0�����ȫ����ȥ
		while (k < num)
		{
			int sum = 0;
			for (int i = 1; i < k; i++) //���������� ����iȡ����k
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
�˿�����Ϸ���Ӧ�ö��Ƚ���Ϥ�ˣ�һ������54����ɣ���3~A��2��4�ţ�С��1�ţ�����1�š�
�����С�����������ַ����ַ�����ʾ�����У�Сдjoker��ʾС������дJOKER��ʾ��������
3 4 5 6 7 8 9 10 J Q K A 2 joker JOKER
���������ƣ�������֮����"-"���ӣ�ÿ���Ƶ�ÿ�����Կո�ָ���"-"����û�пո��磺4 4 4 4-joker JOKER��
��Ƚ������ƴ�С������ϴ���ƣ���������ڱȽϹ�ϵ�����ERROR��
��������
��1������ÿ���ƿ����Ǹ��ӡ����ӡ�˳�ӣ�����5�ţ���������ը�����ĸ����Ͷ����е�һ�֣����������������
�����뱣֤�����ƶ��ǺϷ��ģ�˳���Ѿ���С�������У�
��2������ը���Ͷ������Ժ������ƱȽ�֮�⣬�������͵���ֻ�ܸ���ͬ���͵Ĵ��ڱȽϹ�ϵ
���磬���Ӹ����ӱȽϣ������������Ƚϣ��������ǲ���������磺�����Ӳ�ֳɸ��ӣ���
��3����С��������ƽʱ�˽�ĳ���������ͬ�����ӡ����ӡ������Ƚ������С��˳�ӱȽ���С�ƴ�С��
ը������ǰ�����е��ƣ�ը��֮��Ƚ������С�������������ƣ�
��4������������Ʋ��������ȵ������
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
		//���д�С��ʱ��һ���Ǵ�С�����
		if (str.find("joker JOKER")!=string::npos)
		{
			result = "joker JOKER";
			return result;
		}

		//�������Ʒֿ�,���ڲ�ͬ��string��
		int mid = str.find('-');
		s1 = str.substr(0, mid);
		s2 = str.substr(mid + 1);

		//�õ������Ƶ�' '�������Դ��ж��Ƿ�Ϊ��ͬ���͡�ע�ⲻ��ʹ�ó����жϣ�����Ϊjoker����bug
		int s1_count = count(s1.begin(), s1.end(), ' ');
		int s2_count = count(s2.begin(), s2.end(), ' ');

		//������Ϊ��ͬ�����ͣ��Ƚ���С�Ĵ�С����
		if (s1_count == s2_count)
		{
			//�õ���С�ĵ���
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

		//�����Ʋ���ͬ����ը�����߲���������
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