#pragma once
#include <iostream>
#include <vector>

using namespace std;

class Matrix {
private:
	vector<vector<int>> rows_and_columns;
public:
	void setRowsColumns();
	void transformMatrix();
	void operator=(Matrix& one);
	void operator-=(Matrix& one);
	void operator+=(Matrix& one);
	void operator*=(Matrix& one);
	//Multiply by a scalar
	void operator*=(int someInt);
	friend ostream& operator<<(ostream& os, Matrix& one);

	// Unable to do much work on this since meeting with Jeff due to finals

	//Done:
	// ✓ Matrix Matrix addition
	// ✓ Matrix matrix subtraction
	// ✓ Matrix matrix multiplication
	// ✓ Matrix scalar multiplication
	// ✓ GLSP 
	// ✓ Output the matrix
	// ✓ Transform with some operator

	//TODO:
	// - friend istream& operator>>(istream& is, Matrix& one);
	//		- Read in a matrix from a file
	// - bool linearDependence()
	//		- Checks if the matrix has linearly independent columns / rows
	// - void zeroOut(int one, int two)
	//		- "zeros" out the index (one,two)
	// - Matrix findInverse()
	//		- Find the inverse of some function
	// - Better UI
	//		- Maybe use SFML library to 
	// - REF(matrix one)
	//		- Find the row echelon form of a matrix
	// - RREF(matrix one)
	//		- Find the reduced row echelon form of a matrix
};