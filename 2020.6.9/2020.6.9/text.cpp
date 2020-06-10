#include <iostream>

//不使用算数运算符，实现两个数的相加
class UnusualAdd {
public:
	int addAB(int A, int B) {
		if (0 == B)
		{
			return A;
		}
		int sum = A^B;
		int carry = (A&B) << 1;
		return addAB(sum, carry);
	}
};
