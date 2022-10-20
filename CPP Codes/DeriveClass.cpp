// C++ program for the above approach
#include <iostream>
using namespace std;

class Base {
public:
	virtual void show() { cout << " In Base \n"; }
};

class Derived : public Base {
public:
	void show() { cout << "In Derived \n"; }
};

// Driver's code
int main(void)
{
	Base* bp = new Derived;

	// Function call
	bp->show(); // RUN-TIME POLYMORPHISM
	return 0;
}
