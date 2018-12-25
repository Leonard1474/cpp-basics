#include "func.h"

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