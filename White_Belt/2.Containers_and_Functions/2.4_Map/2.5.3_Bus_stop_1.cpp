#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <unordered_map>
#include <algorithm>

using namespace std;


int main() {
    int N;
    cin >> N;
    map<string, vector<string>> bus_routes;
    vector<string> unordered_buses;

    while (N) {
        string command;
        cin >> command;
        if (command == "NEW_BUS") {
            string bus;
            int cnt_stops;
            cin >> bus >> cnt_stops;
            unordered_buses.push_back(bus);
            while(cnt_stops--) {
                string current_stop;
                cin >> current_stop;
                bus_routes[bus].push_back(current_stop);
            }
        } else if (command == "BUSES_FOR_STOP") {
            string stop;
            cin >> stop;
            int count_buses = 0;

            for (const string& bus : unordered_buses) {
                if (count(bus_routes[bus].begin(), bus_routes[bus].end(), stop)) {
                    cout << bus << ' ';
                    count_buses++;
                }
            }
            if (count_buses) cout << endl;
            else cout << "No stop" << endl;
        } else if (command == "STOPS_FOR_BUS") {
            string bus_route;
            cin >> bus_route;

            if (bus_routes.count(bus_route)) {
                for (const string& c : bus_routes[bus_route]) {
                    cout << "Stop " << c << ": ";
                    int count_buses = 0;
                    for (const string& bus : unordered_buses) {
                        if (bus != bus_route && count(bus_routes[bus].begin(), bus_routes[bus].end(), c)) {
                            cout << bus << ' ';
                            count_buses++;
                        }
                    }
                    if (count_buses) cout << endl;
                    else cout << "no interchange" << endl;
                }
            } else {
                cout << "No bus" << endl;
            }
        } else if (command == "ALL_BUSES") {
            if (bus_routes.empty()) {
                cout << "No buses" << endl;
            } else {
                for (auto c : bus_routes) {
                    cout << "Bus " << c.first << ": ";
                    for (const string& s : c.second) {
                        cout << s << ' ';
                    }
                cout << endl;
                }

            }
        }

        --N;
    }
    return 0;
}
