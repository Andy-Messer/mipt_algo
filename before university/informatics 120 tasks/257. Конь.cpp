#include <iostream>
using namespace std;
int main() {
	int x_1, y_1, x_2, y_2;
	cin >> x_1 >> y_1 >> x_2 >> y_2;
	if (abs(x_1 - x_2) == 2 && abs(y_1 - y_2) == 1 || abs(x_1 - x_2) == 1 && abs(y_1 - y_2) == 2) {
		cout << "YES";
	}
	else {
		cout<<"NO";
	}
}