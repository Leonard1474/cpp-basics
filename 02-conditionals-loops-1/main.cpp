#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

int main() {
	const double kEps = 1e-15;

	double a, b, c, xn, xk, dx;
	cout << "Enter a -> ";
	cin >> a;
	cout << "Enter b -> ";
	cin >> b;
	cout << "Enter c -> ";
	cin >> c;
	cout << "Enter xn -> ";
	cin >> xn;
	cout << "Enter xk (xk >= xn) -> ";
	cin >> xk;
	cout << "Enter dx (dx > 0) -> ";
	cin >> dx;

	if (dx <= 0) {
		cout << "\nInvalid dx. Must be: dx > 0.\n";
	}
	else if (xn > xk) {
		cout << "\nInvalid xk. Must be: xk >= xn.\n";
	}
	else {
		cout << string(37, '-') << endl;
		cout << "|        X        |        F        |\n";
		cout << string(37, '-') << endl;

		cout << fixed;
		cout.precision(3);

		while (xn <= xk) {
			cout << "|" << setw(11) << xn << setw(7) << "|";

			double f;
			if ((xn - 1) < kEps && abs(c) > kEps) {
				f = a * pow(xn, 2) + b / c;
			}
			else if ((xn - 15) > kEps && abs(c) < kEps) {
				if (abs(xn - c) < kEps) {
					cout << "  division by 0  |\n";
				}
				else {
					f = (xn - a) / pow((xn - c), 2);
				}
			}
			else {
				if (abs(c) < kEps) {
					cout << "  division by 0  |\n";
				}
				else {
					f = pow(xn, 2) / pow(c, 2);
				}
			}

			int ac = static_cast<int>(a);
			int bc = static_cast<int>(b);
			int cc = static_cast<int>(c);

			cout << setw(11);
			if (((ac&bc) ^ cc) != 0)
				cout << f;
			else
				cout << static_cast<int>(f);
			cout << setw(8) << "|\n";

			xn += dx;
		}
		cout << string(37, '-');
	}
	return 0;
}