#include <iostream>

using namespace std;

int main() {
	int a, b;
	cin >> a >> b;
	while (a <= b) {
		if (!(a % 2)) {
			cout << a << endl;
			a += 2;
		} else {
			a++;
		}
	}
	return 0;
}


