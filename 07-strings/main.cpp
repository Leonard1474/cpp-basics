#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

void ReadArray(int **a, int N, int M) {
	ifstream fin("file.txt");
	if (!fin.is_open()) {
		cout << "can't open file" << endl;
	}
	else
	{
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				fin >> a[i][j];
			}
		}
	}
	fin.close();
}

void PrintArray(int **a, int N, int M) {
	cout << "Array: " << endl;
	cout << string(21, '-') << endl;
	for (int i = 0; i < N; i++) {
		cout << "|";
		for (int j = 0; j < M; j++) {
			cout << setw(3) << a[i][j] << setw(2) << "|";
		}
		cout << endl;
	}
	cout << string(21, '-') << endl << endl;
}

int FindZeroes(int **a, int N, int M) {
	int result = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (a[i][j] == 0) {
				result += 1;
				break;
			}
		}
	}
	return result;
}

int FindMaxSeries(int **a, int N, int M) {
	int max_series_col = 1,
		series_now = 1,
		column_max_series = -1;

	//find series of identical elements in column
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N - 1; j++) {
			//incrementing series_now if finds identical neighbors
			if (a[j][i] == a[j + 1][i]) {
				series_now += 1;
			}
		}
		//check for find max of series 
		if (series_now > max_series_col) {
			max_series_col = series_now;
			column_max_series = i;
		}
		series_now = 1;
	}
	return column_max_series;
}

int main() {

	int N = 3;
	int M = 4;

	int **array = new int*[N];
	for (int i = 0; i < N; i++) {
		array[i] = new int[M];
	}

	ReadArray(array, N, M);
	PrintArray(array, N, M);

	int zeroes = FindZeroes(array, N, M);
	cout << "Number rows consisting zeroes = ";
	if (zeroes == 0) cout << "No one row!\n\n";
	else cout << zeroes << endl << endl;

	int series = FindMaxSeries(array, N, M);
	cout << "Columns with max series identical neighbors: ";
	if (series == -1) {
		cout << "In all no identical neighbors" << endl;
	}
	else {
		cout << series;
		cout << "  (numbering starts at 0)" << endl;
	}

	return 0;
}