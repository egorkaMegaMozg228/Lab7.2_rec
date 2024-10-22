#include <iostream>
#include <iomanip>
#include <time.h>
using namespace std;
void Create(int** a, const int k, const int n, const int Low, const int High,int i=0,int j=0);
void PrintRow(int** a, const int rowNo, const int colCount, int colNo);
void PrintRows(int** a, const int rowCount, const int colCount, int rowNo);
int Result1(int** a, const int k, const int n, int& S, int i, int j, int min);
int Result(int** a, const int k, const int n, int& S, int i, int j, int min);
int main()
{
	srand((unsigned)time(NULL));
	int Low = 7;
	int High = 65;
	int k, n;
	cout << "k = "; cin >> k;
	cout << "n = "; cin >> n;
	int** a = new int* [k];
	for (int i = 0; i < k; i++)
		a[i] = new int[n];
	Create(a, k, n, Low, High);
	PrintRows(a, k, n,0);
	int S = 0;
	Result(a, k, n, S,0,0,0);
	cout << "S = " << S << endl;

	for (int i = 0; i < k; i++)
		delete[] a[i];
	delete[] a;
	return 0;
}
void Create(int** a, const int rowCount, const int colCount, const int Low,
	const int High, int i, int j)
{
	if (i < rowCount) {
		if (j < colCount) {
			a[i][j] = Low + rand() % (High - Low + 1);
			Create(a, rowCount, colCount, Low, High, j + 1, i);
		}
		Create(a, rowCount, colCount, Low, High, j, i + 1);
	}
}
void PrintRows(int** a, const int rowCount, const int colCount, int rowNo)
{
	PrintRow(a, rowNo, colCount, 0);
	if (rowNo < rowCount - 1)
		PrintRows(a, rowCount, colCount, rowNo + 1);
	else
		cout << endl;
}
void PrintRow(int** a, const int rowNo, const int colCount, int colNo)
{
	cout << setw(4) << a[rowNo][colNo];
	if (colNo < colCount - 1)
		PrintRow(a, rowNo, colCount, colNo + 1);
	else
		cout << endl;
}
int Result(int** a, const int k, const int n, int& S, int i, int j, int min) {
	if (i < k) {
		if (i % 2 != 0) { 
			min = a[i][0]; 
			min = Result1(a, k, n, S, i, 0, min); 
			S += min;
		}
		Result(a, k, n, S, i + 1, j, min); 
	}
	return S;
}

int Result1(int** a, const int k, const int n, int& S, int i, int j, int min) {
	if (j < n) {
		if (a[i][j] < min) {
			min = a[i][j];  
		}
		return Result1(a, k, n, S, i, j + 1, min); 
	}
	return min; 
}
