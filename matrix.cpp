#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include "matrix.h"

using std::cout;
using std::cin;

void Matrix::setRowsColumns() {
	string answer;
	int rows;
	int columns;
	int someAns;
	cout << "Enter amount of rows: ";
	cin >> answer;
	rows = stoi(answer);
	cout << endl;
	cout << "Enter amount of columns: ";
	cin >> columns;
	cout << endl;
	for (int i = 0; i < rows; i++) {
		vector<int> someVec;
		rows_and_columns.push_back(someVec);
	}
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < columns; j++) {
			cout << "Entry " << j + 1 << " in row " << i + 1 << ": ";
			cin >> answer;
			cout << endl;
			someAns = stoi(answer);
			rows_and_columns[i].push_back(someAns);
		}
	}
	return;
}

void Matrix::transformMatrix() {
	Matrix m;
	for (int i = 0; i < rows_and_columns[0].size(); i++) {
		vector<int> someVec;
		m.rows_and_columns.push_back(someVec);
		for (int k = 0; k < rows_and_columns.size(); k++) {
			m.rows_and_columns[i].push_back(rows_and_columns[k][i]);
		}
	}
	rows_and_columns = m.rows_and_columns;
	return;
}

void Matrix::operator*=(Matrix& one) {
	if (rows_and_columns.size() == 0 || one.rows_and_columns.size() == 0) {
		cout << "Empty Matrix\n";
		return;
	}
	else if (rows_and_columns[0].size() != one.rows_and_columns.size()) {
		cout << "Inner Dimensions Do Not Agree For Matrix Multiplication! Jeff Would Be Mad!\n";
		return;
	}
	//matrix one = mxp
	//matrix two = pxn
	int m = rows_and_columns.size(); // these variables are redundant -- only there for dimension purposes
	int p = rows_and_columns[0].size();
	int n = one.rows_and_columns[0].size();
	Matrix mat;
	for (int i = 0; i < m; i++)
	{
		vector<int> someVec;
		mat.rows_and_columns.push_back(someVec);
		for (int k = 0; k < n; k++)
		{
			mat.rows_and_columns[i].push_back(0);
		}
	}
	if (rows_and_columns[0].size() == one.rows_and_columns.size()) {
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				for (int k = 0; k < p; k++) {
					mat.rows_and_columns[i][j] += rows_and_columns[i][k] * one.rows_and_columns[k][j];
				}
			}
		}
		rows_and_columns = mat.rows_and_columns;
		return;
	}
	return;
}

void Matrix::operator*=(int someInt) {
	if (rows_and_columns.size() == 0) {
		cout << "Empty Matrix!\n";
		return;
	}
	for (int i = 0; i < rows_and_columns.size(); i++) {
		for (int k = 0; k < rows_and_columns[0].size(); k++) {
			rows_and_columns[i][k] *= someInt;
		}
	}
	return;
}

void Matrix::operator+=(Matrix& one) {
	if (rows_and_columns.size() == 0 || one.rows_and_columns.size() == 0) {
		cout << "Empty Matrix\n";
		return;
	}
	if (rows_and_columns.size() == one.rows_and_columns.size() && rows_and_columns[0].size() == one.rows_and_columns[0].size()) {
		for (int i = 0; i < rows_and_columns.size(); i++) {
			for (int j = 0; j < rows_and_columns[0].size(); j++) {
				rows_and_columns[i][j] += one.rows_and_columns[i][j];
			}
		}
	}
	cout << "add\n";
	return;
}

void Matrix::operator-=(Matrix& one) {
	if (rows_and_columns.size() == 0 || one.rows_and_columns.size() == 0) {
		cout << "Empty Matrix\n";
		return;
	}
	if (rows_and_columns.size() == one.rows_and_columns.size() && rows_and_columns[0].size() == one.rows_and_columns[0].size()) {
		for (int i = 0; i < rows_and_columns.size(); i++) {
			for (int j = 0; j < rows_and_columns[0].size(); j++) {
				rows_and_columns[i][j] -= one.rows_and_columns[i][j];
			}
		}
	}
	cout << "subtract\n";
	return;
}

void Matrix::operator=(Matrix& one) {
	rows_and_columns = one.rows_and_columns;
	return;
}

ostream& operator<<(ostream& os, Matrix& one) {
	for (int i = 0; i < one.rows_and_columns.size(); i++) {
		string somestr;
		os << "| ";
		for (int j = 0; j < one.rows_and_columns[0].size(); j++) {
			stringstream ss;
			ss << one.rows_and_columns[i][j];
			somestr += ss.str();
			somestr += " | ";
		}
		somestr += '\n';
		os << somestr;
	}
	return os;
}