#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    cout << "Hello World!" << endl;
    string str = "Hello";
    cout << str << endl;
    vector<int> vec = {1, 5, 2, 7, 4, 9};
    sort(begin(vec), end(vec));
    for (auto c : vec)
    {
        cout << c << ' ';
    }

    return 0;
}