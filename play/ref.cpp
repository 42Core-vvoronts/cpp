#include <iostream>

void byptr(int *ptr)
{

}

void byfer(int& ref)
{

}

int main() {
    int var = 1;
	int var_2 = 2;

	int *ptr = &var;
	int& ref = var;

	*ptr = 10;
	ref = 20;

	ptr = &var_2; // keeps address of var_2
	ref = var_2; // keeps address of var, value of var_2

    return 0;
}