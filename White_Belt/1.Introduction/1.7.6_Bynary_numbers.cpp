#include <iostream>
#include <vector>

using namespace std;

int main() {
	int x;
	cin >> x;
	vector<int> binNums;
	while(x) {
		int c = x % 2;
		x /= 2;
		binNums.push_back(c);
	}
	for (int i = binNums.size() - 1; i >= 0; i--) {
		cout << binNums[i];
	}
	return 0;
}


