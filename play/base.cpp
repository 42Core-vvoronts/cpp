#include <iostream> // cout, cin
#include <string> // string

namespace MathUtils
{
	// overloaded functions
	// 1
	int add(int a, int b)
	{
		std::cout << "int addition" << std::endl;
		return a + b;
	}
	// 2
	double add(double a, double b)
	{
		std::cout << "float addition" << std::endl;
		return a + b; 

	}
	void mult(int& num, int factor)
	{
		num *= factor;
	}
	void mult(int *num, int factor)
	{
		*num *= factor;
	}

}


void moduleOne()
{
	std::cout << "Add int: " << MathUtils::add(5, 3) << std::endl;
	std::cout << "Add float: " << MathUtils::add(5.5, 3.8) << std::endl;

	int num;
	std::cout << "Enter: ";
	std::cin >> num;
	int& numr = num;
	std::cout << "Original val: " << num << std::endl;
	std::cout << "Original ref: " << numr << std::endl;
	MathUtils::mult(numr, 3);
	std::cout << "Modified val: " << num << std::endl;
	std::cout << "Modified ref: " << numr << std::endl;

	std::cout << "Enter: ";
	std::cin >> num;
	int *nump = &num;
	std::cout << "Original val: " << num << std::endl;
	std::cout << "Original ptr: " << *nump << std::endl;
	MathUtils::mult(nump, 3);
	std::cout << "Modified val: " << num << std::endl;
	std::cout << "Modified ptr: " << *nump << std::endl;


	// std::cout << "Enter: ";
	// std::cin >> num;
	// std::cout << "Original: " << num << std::endl;
	// MathUtils::mult(num, 3);
	// std::cout << "Modified: " << num << std::endl;
	
}

int main()
{
	moduleOne();

	return 0;
}