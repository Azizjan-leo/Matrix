// Matrix.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <math.h>       /* pow */
#include <cmath>
#include <clocale>
#include "Matrix.h"
#include <cctype>
#include <Windows.h>

double matrix[8][8];
const double eulerConstant = std::exp(1.0);
double vector = 0.0;
double func = 0.0;

void fill() 
{
	for (size_t i = 0; i < 8; i++)
	{
		for (size_t j = 0; j < 8; j++)
		{
			matrix[i][j] = pow(-1*(2,5/((3*j)+2)),i) + pow(eulerConstant,(cos(j)));
		}
	}
}

void vectorCalc()
{
	for (int i = 0; i < 8; ++i)
		vector += matrix[i][i];
}

void funcCalc()
{
	double maxItem = 0.0;
	double absMinItem = abs(matrix[0][0]);
	int indexOfMin = 0;

	for (int i = 0; i < 8; ++i) 
	{
		if (matrix[i][i] > maxItem)
			maxItem = matrix[i][i];
		if (abs(matrix[i][i]) < absMinItem)
		{
			indexOfMin = i;
			absMinItem = abs(matrix[i][i]);
		}
	}

	func = maxItem - indexOfMin;
}

void print() 
{	
	std::cout << "The matrix:\n\n";
	for (size_t i = 0; i < 8; i++)
	{
		for (size_t j = 0; j < 8; j++)
		{
			std::cout << matrix[i][j] << ' ';
		}
		std::cout << std::endl;
	}

	std::wcout << "\nThe vector: " << vector << std::endl;

	std::cout << "\nThe function: " << func << std::endl;
}

int main()
{
	fill();
	vectorCalc();
	funcCalc();
	print();
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
