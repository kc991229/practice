#include <iostream>

//不使用算数运算符，实现两个数的相加

/*
拆分加法的本质，加和进位。对于二进制来说，1和0的组合可以直接加，用逻辑运算异或实现。
而对于1和1的组合，需要进位，利用与运算得到进位的位，左移一位即进位后的结果，
该结果和之前加得到的结果异或，如果吻合则会满足二者相与为0，
否则还需要进一步操作即再左移再异或再与运算判断
*/
size_t addAB(size_t A, size_t B)
{
	size_t temp1,  temp2;
	temp1 = A^B;
	temp2 = (A&B) << 1;

	if (temp2 == 0)
		return temp1;
	else
		return addAB(temp1, temp2);
}
int main()
{
	std::cout << addAB(1, 9);
	return 0;
}
