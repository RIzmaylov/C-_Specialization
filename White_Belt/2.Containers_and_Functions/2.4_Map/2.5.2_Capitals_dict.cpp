#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;


int main() {
    int N;
    cin >> N;
    map<string, string> countries;

    while (N) {
        string command;
        cin >> command;

        if (command == "CHANGE_CAPITAL") {
            string country, capital;
            cin >> country >> capital;

            if (!countries.count(country)) {
                countries[country] = capital;
                cout << "Introduce new country " << country << " with capital " << countries[country] << endl;
            } else if (countries[country] == capital){
                cout << "Country " << country << " hasn't changed its capital" << endl;
            } else {
                cout << "Country " << country << " has changed its capital from " << countries[country] << " to " << capital << endl;
                countries[country] = capital;
            }
        } else if (command == "RENAME") {
            string old_country_name, new_country_name;
            cin >> old_country_name >> new_country_name;

            if (countries.count(old_country_name) && !countries.count(new_country_name)) {
                cout << "Country " << old_country_name << " with capital " << countries[old_country_name] << " has been renamed to " << new_country_name << endl;
                countries[new_country_name] = countries[old_country_name];
                countries.erase(old_country_name);
            } else {
                cout << "Incorrect rename, skip" << endl;
            }
        } else if (command == "ABOUT") {
            string country;
            cin >> country;

            if(!countries.count(country)) {
                cout << "Country " << country << " doesn't exist" << endl;
            } else {
                cout << "Country " << country << " has capital " << countries[country] << endl;
            }
        } else if (command == "DUMP") {
            if(countries.empty()) {
                cout << "There are no countries in the world" << endl;
            } else {
                for (const auto& item : countries) {
                    cout << item.first << '/' << item.second << ' ';
                }
                cout << endl;
            }
        }

        --N;
    }
    return 0;
}

