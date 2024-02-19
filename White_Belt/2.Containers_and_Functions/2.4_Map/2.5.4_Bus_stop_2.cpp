#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>

using namespace std;


int main() {
    map<vector<string>, int> buses;
    int N;
    cin >> N;
    int counter = 0;
    while (N--) {
        int count_buses;
        cin >> count_buses;
        vector<string> temp_buses(count_buses);
        for (string& c : temp_buses) {
            cin >> c;
        }
        if (buses.count(temp_buses)) {
            cout << "Already exists for " << buses[temp_buses] << endl;
        } else {
            buses[temp_buses] = ++counter;
            cout << "New bus " << counter << endl;
        }
    }
    return 0;
}
