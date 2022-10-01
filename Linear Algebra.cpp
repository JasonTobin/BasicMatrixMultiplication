#include <iostream>
#include "matrix.h"

using std::cout;

int main()
{
	Matrix mat;
	mat.setRowsColumns();
	Matrix mat2 = mat;
	for (int i = 0; i < 2; i++) {
		mat *= mat2;
	}
	cout << mat;
	return 0;
}