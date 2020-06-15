#include <iostream>
using namespace std;

class A
{
public:
	void foo()
	{
		cout << "foo";
	}
	virtual void bar()
	{
		cout << "bar";
	}
	A()
	{
		bar();
	}
};
class B :public A
{
public:
	void foo()
	{
		cout << "b_foo";
	}
	void bar()
	{
		cout << "b_bar";
	}
};
int main()
{
	B *p = new B;
	p->foo();
	p->bar();
	return 0;
}