#include "func.h"

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