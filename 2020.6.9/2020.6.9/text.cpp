#include <iostream>

//��ʹ�������������ʵ�������������
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
