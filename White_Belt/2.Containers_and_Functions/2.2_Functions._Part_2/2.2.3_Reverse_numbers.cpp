#include <iostream>
#include <vector>
#include <string>

using namespace std;

void Reverse (vector<int>& v) {
    for (size_t i = 0; i < v.size() / 2; ++i) {
        swap(v[i], v[v.size() - 1 - i]);
    }
}

int main() {
//    vector<int> numbers = {};
//    Reverse(numbers);
//    for (auto w : numbers) {
//        cout << w << ' ';
//    }
    return 0;
}


