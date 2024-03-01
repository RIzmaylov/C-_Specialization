#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>

using namespace std;


int main() {
    int N;
    cin >> N;
    set<string> strings;
    while (N--) {
        string temp_string;
        cin >> temp_string;
        strings.insert(temp_string);
    }
    cout << strings.size() << endl;
    return 0;
}
