#include <iostream>
#include <string>
#include <fstream>

using namespace std;

bool DoubleDigitInString(string s) {
	if (isdigit(s[s.length() - 1]) &&
		isdigit(s[s.length() - 2]) &&
		!isdigit(s[s.length() - 3])) {
		return true;
	}

	for (int i = 0; i < s.length() - 2; i++)
	{
		if ((isdigit(s[i])) &&
			(isdigit(s[i + 1])) &&
			(!isdigit(s[i + 2]))) {
			return true;
		}
	}
	return false;
}

int main() {
	string s, file_name;

	cout << "Write  file name (default name 'a') -> ";
	cin >> file_name;
	file_name += ".txt";
	ifstream fin(file_name);

	if (!fin.is_open()) {
		cout << "can't open file!" << endl;
		return 1;
	}

	cout << "Strings containing double-digit numbers:" << endl;
	while (getline(fin, s, '\n')) {
		if (DoubleDigitInString(s))
			cout << s << endl;
	}

	fin.close();
	return 0;
}