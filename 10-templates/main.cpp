#include <iostream> //Input/Output 
#include <iomanip> //setw()
#include <fstream> //file input
#include <string> //for input string

using namespace std;

template<class T>
void ReadArray(T **a, int N, int M, string name) {
	ifstream fin(name + ".txt");
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

template<class T>
void PrintArray(T **a, int N, int M) {
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

template<class T>
int FindZeroes(T **a, int N, int M) {
	const double kEps = 1e-15;
	int result = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (abs(a[i][j]) < kEps) {
				result += 1;
				break;
			}
		}
	}
	return result;
}

template<class T>
int FindMaxSeries(T **a, int N, int M) {
	int max_series_col = 0,
		series_now = 0,
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


template <class TypeAr>
void start(string name) {
	int N = 3;
	int M = 4;

	TypeAr **array = new TypeAr*[N];
	for (int i = 0; i < N; i++) {
		array[i] = new TypeAr[M];
	}

	ReadArray<TypeAr>(array, N, M, name);
	PrintArray<TypeAr>(array, N, M);

	int zeroes = FindZeroes<TypeAr>(array, N, M);
	cout << "Number rows consisting zeroes = ";
	if (zeroes == 0) cout << "No one row!\n\n";
	else cout << zeroes << endl << endl;

	int series = FindMaxSeries<TypeAr>(array, N, M);
	cout << "Column with max series identical neighbors: ";
	if (series == -1) {
		cout << "In all no identical neighbors" << endl;
	}
	else {
		cout << series;
		cout << "  (numbering starts at 0)" << endl;
	}
}

int main() {
error:
	cout << "Select the data type (0-integer, 1-double, 2-float): ";
	string select;
	cin >> select;
	if (select == "0") {
		start<int>("int");
	}
	else if (select == "1") {
		start<double>("double");
	}
	else if (select == "2") {
		start<float>("float");
	}
	else {
		cout << "Error input! (Only 0/1/2)" << endl;
		goto error;
	}
	return 0;
}