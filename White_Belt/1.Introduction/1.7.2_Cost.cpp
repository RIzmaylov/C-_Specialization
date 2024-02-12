#include <iostream>

using namespace std;

int main() {
	// double n, a, b, x, y;
	// cin >> n >> a >> b >> x >> y;
	// if (n > b) {
	// 	cout << n - n * y / 100 << endl;
	// } else if (n > a) {
	// 	cout << n - n * x / 100 << endl;
	// } else {
	// 	cout << n << endl;
	// }

    double N, A, B, X, Y;
    std::cin >> N >> A >> B >> X >> Y;
    if (N > B) N *= (100 - Y) * 0.01;
    else if (N > A)  N *= (100 - X) * 0.01;
    std::cout << N;
	return 0;
}
