#include <iostream>
#include <cstdlib>
#include <ct/ime>
#include <iomanip>
#include <string>

using namespace std;

void PrintArray(int array[], int size) {
	cout << string(61, '-') << endl;
	cout << "|";

	for (int i = 0; i < size; i++) {
		cout << setw(2) << "[" << i << "]" << setw(2) << "|";
	}

	cout << "<- Index";
	cout << endl << string(61, '-') << endl << "|";

	for (int i = 0; i < size; i++) {
		cout << setw(3) << array[i] << setw(3) << "|";
	}

	cout << "<- array[i]";
	cout << endl;
	cout << string(61, '-') << endl;
	cout << endl;
}

unsigned int IndexOfMinModuloElement(int a[], int const size) {
	unsigned int index_min = 0;
	int min = a[0];
	for (int i = 1; i < size; i++)
	{
		if (abs(min) > abs(a[i])) {
			min = a[i];
			index_min = i;
		}
	}
	return index_min;
}

int SumAfterSubzeroElement(int a[], int const size, int first_subzero) {
	int sum = 0;
	for (int i = first_subzero + 1; i < size; i++)
	{
		sum += a[i];
	}
	return sum;
}

bool InInterval(int x, int a, int b) {
	if (x >= a && x <= b)
		return true;
	else
		return false;
}

void CutArray(int ar[], int a, int b, int const size, int B[]) {
	int add_index = 0;
	for (int i = 0; i < size; i++)
	{
		B[i] = 0;
		if (InInterval(ar[i], a, b)) {
			B[add_index] = ar[i];
			add_index++;
		}
	}
}

int main() {
	int const kArraySize = 10;
	int array[kArraySize];

	srand((unsigned)time(NULL));

	//generation array 
	//and find first subzero element
	int index_firs_subzero;
	bool subzero_finded = false;
	for (int i = 0; i < kArraySize; i++) {
		array[i] = int(pow(-1, rand() % 2))*(rand() % 10); //[-9..9]
		if (!subzero_finded)
			if (array[i] < 0) {
				index_firs_subzero = i;
				subzero_finded = true;
			}
	}

	cout << "Starting Array :" << endl;
	PrintArray(array, kArraySize);

	cout << "\nIndex of min modulo element -> ";
	cout << IndexOfMinModuloElement(array, kArraySize) << endl;

	cout << "\nSum after first subzero element = ";
	if (!subzero_finded) {
		cout << "No subzero elements in the array!\n";
	}
	else if (kArraySize - index_firs_subzero == 1) {
		cout << "First subzero element is last element in the array!\n";
	}
	else {
		cout << SumAfterSubzeroElement(array, kArraySize, index_firs_subzero);
		cout << endl << endl;
	}

	cout << "Enter interval [a;b] (e.g. \"-3 4\" for [-3;4] interval ) -> ";
	int a, b;
	cin >> a >> b;
	if ((a == b) || (a > b))
		cout << "Invalid interval(must be a<b)!\n\n";
	else {
		int B[kArraySize];
		CutArray(array, a, b, kArraySize, B);
		cout << "Cut array: \n";
		PrintArray(B, kArraySize);
	}

	return 0;
}