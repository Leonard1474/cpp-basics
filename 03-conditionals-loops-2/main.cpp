#include <iostream>
#include <cmath>
#include <iomanip>
#include <string>

using namespace std;

double arth(double x) {
	return log(sqrt(abs(1.0 - pow(x, 2))) / abs((1.0 - x)));
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
	else if (abs(xn - 1) < eps) {
		cout << "\nInvalid xn. Must be: |xn| > 1.\n";
	}
	else {
		cout << string(74, '-') << endl;
		cout << "|         x         ";
		cout << "|   arth(xn)(mine)  ";
		cout << "|  arth(xn)(cmath)  ";
		cout << "| iterations |\n";
		cout << string(74, '-') << endl;

		cout << fixed;
		cout.precision(6);

		for (; xn <= xk; xn += dx) {
			int n = 1;
			double nth_term = 1 / xn;
			double my_arth = nth_term;
			while (abs(nth_term) > eps) {
				nth_term = 1 / (pow(xn, n * 2 + 1)*(n * 2 + 1));
				my_arth += nth_term;
				n++;
				if (n > kMaxIters) break;
			}

			cout << "|" << setw(13) << xn << setw(7) << "|" << setw(14);
			if (n <= kMaxIters)
				cout << my_arth << setw(6) << "|";
			else
				cout << " limit is exceeded |";
			cout << setw(14) << arth(xn) << setw(6) << "|";
			cout << setw(7) << n << setw(7) << "|\n";

		}
		cout << string(74, '-');
	}

	return 0;
