#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>

using namespace std;

int main() {
    map<set<string>, int> buses;
    int N;
    cin >> N;
    int counter = 0;
    while (N--) {
        int count_buses;
        cin >> count_buses;
        set<string> temp_buses;
        while (count_buses--) {
            string c;
            cin >> c;
            temp_buses.insert(c);
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

