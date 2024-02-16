#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    vector<int> days_per_month = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int current_month = 1;
    vector<vector<string>> month(days_per_month[current_month - 1]);

    int count_comms;
    cin >> count_comms;

    while (count_comms) {
        string command;
        cin >> command;

        if (command == "ADD") {
            int day_num = 0;
            string goods;
            cin >> day_num >> goods;
            if (day_num <= month.size()) month[day_num - 1].push_back(goods);

        } else if (command == "DUMP") {
            int day_num = 0;
            cin >> day_num;
            if (day_num <= month.size()) {
                cout << month[day_num - 1].size();
                for (auto c : month[day_num - 1]) {
                    cout << ' ' << c;
                }
                cout << endl;
            }
        } else if (command == "NEXT") {
            if (current_month == 12) current_month = 1;
            else ++current_month;

            if (month.size() > days_per_month[current_month - 1]) {
                for (int i = days_per_month[current_month - 1]; i < month.size(); ++i) {
                    month[days_per_month[current_month - 1] - 1].insert(end(month[days_per_month[current_month - 1] - 1]), begin(month[i]), end(month[i]) );
                }
                month.resize(days_per_month[current_month - 1]);
                //cout << current_month << endl;
            } else {
                month.resize(days_per_month[current_month - 1]);
                //cout << current_month << endl;
            }
        }
        --count_comms;
    }

    return 0;
}
