/*
��������һ�����ֳ��ֵĴ����������鳤�ȵ�һ�룬���ҳ�������֡�
��������һ������Ϊ9������{1,2,3,2,2,2,5,4,2}��
��������2�������г�����5�Σ��������鳤�ȵ�һ�룬������2����������������0��
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int MoreThanHalfNum_Solution(vector<int> numbers)
{
	if (numbers.empty())
		return 0;
	sort(numbers.begin(), numbers.end());
	int middle = numbers[numbers.size() / 2];
	int count = 0; // ���ִ���
	for (int i = 0; i<numbers.size(); ++i)
	{
		if (numbers[i] == middle)
			++count;
	}
	return (count>numbers.size() / 2) ? middle : 0;
}

/*
����һ���򵥴����¼����Сģ�飬�ܹ���¼����Ĵ������ڵ��ļ����ƺ��кš�

����

1�� ��¼���8�������¼��ѭ����¼������˵���ֻ��������ֵİ��������¼����
����ͬ�Ĵ����¼�����ļ������������16λ���ƺ��к���ȫƥ�䣩ֻ��¼һ��������������ӣ�

2�� ����16���ַ����ļ����ƣ�ֻ��¼�ļ��������Ч16���ַ���

3�� ������ļ����ܴ�·������¼�ļ����Ʋ��ܴ�·����

��������:
һ�л�����ַ�����ÿ�а�����·���ļ����ƣ��кţ��Կո������

�������:
�����еļ�¼ͳ�Ʋ�������������ʽ���ļ��� �������� ��Ŀ��һ���ո�������磺

ʾ��1
����
E:\V1R2\product\fpgadrive.c   1325
���
fpgadrive.c 1325 1
*/

#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>

string getFileName(string path){
	int pos = path.rfind('\\');
	return path.substr(pos + 1);
}

string modifyName(string name){
	if (name.size() > 16){
		name = name.substr(name.size() - 16);
	}

	return name;
}

struct ErrRecord{
	string file;
	int lineNo;
	int count;

	ErrRecord(string file, int lineNo){
		this->file = file;
		this->lineNo = lineNo;
		count = 1;
	}

	bool operator==(const ErrRecord & a){
		return (file == a.file) && (lineNo == a.lineNo);
	}
};

int main()
{
	string file;
	int lineNo;
	vector<ErrRecord> myvec;
	while (cin >> file >> lineNo){
		ErrRecord record(getFileName(file), lineNo);
		auto res = find(myvec.begin(), myvec.end(), record);
		if (res == myvec.end()){
			myvec.push_back(record);
		}
		else{
			res->count++;
		}
	}

	int count = 0;
	for (auto item : myvec){
		if (count + 8 >= myvec.size()){
			cout << modifyName(item.file) << " " << item.lineNo << " "
				<< item.count << endl;
		}
		count++;
	}
	return 0;
}
