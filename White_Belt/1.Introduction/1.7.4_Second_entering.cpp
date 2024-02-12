#include <iostream>
#include <string>

using namespace std;

int main() {
	string s;
	cin >> s;
	int count = -2;
	for (size_t i = 0; i < s.size(); ++i) {
		if (s[i] == 'f') {
			++count;
		}
		if (count == 0) {
			cout << i << endl;
			return 0;
		}
	}
	cout << count << endl;
	return 0;
}


