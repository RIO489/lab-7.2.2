// Lab_7_2_2.cpp
// < Гамаюнов Олександр >
// Лабораторна робота № 7.2.2)
// Опрацювання багатовимірних масивів рекурсивним способами.
// Варіант 5

#include <iostream>
#include <iomanip>
#include <time.h>
using namespace std;
void Create1(int** a, const int n, const int k, const int Low, const int High,int i);
void Create2(int** a, const int n, const int k, const int Low, const int High, int i,int j);
void Print1(int** a, const int n, const int k,int i);
void Print2(int** a, const int n, const int k,int i,int j);
int SumMinEven1(int** a, const int n, const int k, int minEven,int S,int i);
int SumMinEven2(int** a, const int n, const int k, int minEven,int i,int j,int S,int index);
int main()
{
	srand((unsigned)time(NULL));
	int Low = 7;
	int High = 65;
	int n;
	cout << "n = "; cin >> n;
	int k;
	cout << "k = "; cin >> k;
	int** a = new int* [n];
	for (int i = 0; i < n; i++)
		a[i] = new int[k];
	Create1(a, n, k, Low, High,0);
	Print1(a, n, k,0);
	cout << "Sum Min Element = " << SumMinEven1(a, n, k, 0,0,0) << endl;
	for (int i = 0; i < n; i++)
		delete[] a[i];
	delete[] a;
	return 0;
}
void Create1(int** a, const int n, const int k, const int Low, const int High, int i)
{
	if (i < n)
	{
		Create2(a, n, k, Low, High, i, 0);
		return Create1(a, n, k, Low, High, i + 1);
	}
}
void Create2(int** a, const int n, const int k, const int Low, const int High,int i,int j)
{
	if (j < k)
	{
		a[i][j] = Low + rand() % (High - Low + 1);
		return Create2(a, n, k, Low, High, i, j + 1);
	}
}
void Print1(int** a, const int n, const int k,int i)
{
	cout << endl;
	if(i < n)
	{
		Print2(a, n, k, i, 0);
		return Print1(a, n, k, i+1);
	}
	cout << endl;
}
void Print2(int** a, const int n, const int k,int i,int j)
{
		if (j < k)
		{
			cout << setw(4) << a[i][j];
			return Print2(a, n, k, i,j + 1);
		}
}
int SumMinEven1(int** a, const int n, const int k, int minEven,int S,int i)
{
	if(i < n)
	{
		if (i % 2 != 0)
		{
			S = SumMinEven2(a, n, k, minEven, i, 0, S, 0);
			return SumMinEven1(a, n, k, minEven, S, i + 1);
		}
		return SumMinEven1(a, n, k, minEven, S, i + 1);
	}
	return S;
}
int SumMinEven2(int** a, const int n, const int k, int minEven,int i,int j,int S,int index)
{
			if(j < k)
			{
				if (a[i][j] < a[i][index])
					index = j;
				return SumMinEven2(a, n, k, minEven, i, j + 1,S,index);
			}
			minEven = a[i][index];
			S += minEven; 
			cout << "Min a[" << i << "][" << index << "] = " << minEven << endl;
				return S;
}
