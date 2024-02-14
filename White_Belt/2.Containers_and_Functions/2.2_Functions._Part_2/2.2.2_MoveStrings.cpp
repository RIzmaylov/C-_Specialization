#include <iostream>
#include <vector>
#include <string>

using namespace std;

void MoveStrings(vector<string>& source, vector<string>& destination) {
    for (auto i : source) {
        destination.push_back(i);
    }
    source.clear();
}

int main() {
    vector<string> source = {"a", "b", "c"};
    vector<string> destination = {"z"};
    MoveStrings(source, destination);
// source должен оказаться пустым
// destination должен содержать строки "z", "a", "b", "c" именно в таком порядке
    for (auto i : destination) {
        cout << i << ' ';
    }
    cout << endl;
    for (auto i : source) {
        cout << i << ' ';
    }
    return 0;
}

