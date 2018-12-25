#include <iostream>
#include <cmath>
#include <iomanip>
#include <string>

using namespace std;

double arth(double x) {
	return log(sqrt(abs(1.0 - pow(x, 2))) / abs((1.0 - x)));
}

void PrintTableHead() {
	cout << string(74, '-') << endl;
	cout << "|         x         ";
	cout << "|   arth(xn)(mine)  ";
	cout << "|  arth(xn)(cmath)  ";
	cout << "| iterations |\n";
	cout << string(74, '-') << endl;
}

double ComputeSeries(double x, double eps, int &n, const int kMaxIters) {
	n = 1;
	double nth_term = 1 / x;
	double my_arth = nth_term;
	while (abs(nth_term) > eps) {
		nth_term = 1 / (pow(x, n * 2 + 1)*(n * 2 + 1));
		my_arth += nth_term;
		n++;
		if (n > kMaxIters) break;
	}
	return my_arth;
}

void PrintTableRow(double x, double func, int n, const int kMaxIters) {
	cout << "|" << setw(13) << x << setw(7) << "|" << setw(14);
	if (n <= kMaxIters)
		cout << func << setw(6) << "|";
	else
		cout << " limit is exceeded |";
	cout << setw(14) << arth(x) << setw(6) << "|";
	cout << setw(7) << n << setw(7) << "|\n";
}

int main() {
	const int kMaxIters = 1000;

	double xn, xk, dx, eps;
	cout << "Enter xn -> ";
	cin >> xn;
	cout << "Enter xk (xk >= xn) -> ";
	cin >> xk;
	cout << "Enter dx (dx > 0) -> ";
	cin >> dx;
	cout << "Enter eps (eps > 0) -> ";
	cin >> eps;

	if (dx <= 0) {
		cout << "\nInvalid dx. Must be: dx > 0.\n";
	}
	else if (eps <= 0) {
		cout << "\nInvalid eps. Must be: eps > 0.\n";
	}
	else if (xn > xk) {
		cout << "\nInvalid xk. Must be: xk >= xn.\n";
	}
	else {
		PrintTableHead();

		cout << fixed;
		cout.precision(6);

		for (; xn <= xk; xn += dx) {
			int n;
			double my_arth = ComputeSeries(xn, eps, n, kMaxIters);
			PrintTableRow(xn, my_arth, n, kMaxIters);
		}
		cout << string(74, '-');
	}

	return 0;
}