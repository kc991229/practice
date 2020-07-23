/*
数组中有一个数字出现的次数超过数组长度的一半，请找出这个数字。
例如输入一个长度为9的数组{1,2,3,2,2,2,5,4,2}。
由于数字2在数组中出现了5次，超过数组长度的一半，因此输出2。如果不存在则输出0。
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
	int count = 0; // 出现次数
	for (int i = 0; i<numbers.size(); ++i)
	{
		if (numbers[i] == middle)
			++count;
	}
	return (count>numbers.size() / 2) ? middle : 0;
}

/*
开发一个简单错误记录功能小模块，能够记录出错的代码所在的文件名称和行号。

处理：

1、 记录最多8条错误记录，循环记录（或者说最后只输出最后出现的八条错误记录），
对相同的错误记录（净文件名（保留最后16位）称和行号完全匹配）只记录一条，错误计数增加；

2、 超过16个字符的文件名称，只记录文件的最后有效16个字符；

3、 输入的文件可能带路径，记录文件名称不能带路径。

输入描述:
一行或多行字符串。每行包括带路径文件名称，行号，以空格隔开。

输出描述:
将所有的记录统计并将结果输出，格式：文件名 代码行数 数目，一个空格隔开，如：

示例1
输入
E:\V1R2\product\fpgadrive.c   1325
输出
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
