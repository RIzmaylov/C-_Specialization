#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<int> Reversed (const vector<int>& v) {
    vector<int> temp = v;
    for (size_t i = 0; i < temp.size() / 2; ++i) {
        swap(temp[i], temp[temp.size() - 1 - i]);
    }
    return temp;
}

int main() {
//    vector<int> numbers = {1, 2};
//    vector<int> numbers2 = Reverse(numbers);
//    for (auto w : numbers2) {
//        cout << w << ' ';
//    }
    return 0;
}


