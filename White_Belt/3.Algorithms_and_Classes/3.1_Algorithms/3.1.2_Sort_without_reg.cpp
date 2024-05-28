#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;


int main()
{
    int N;
    cin >> N;
    vector<string> strings(N);
    for (auto& c : strings) {
        cin >> c;
    }

    sort(strings.begin(), strings.end(), [](const string& s1, const string& s2) {
            string s1_temp, s2_temp;
            for (auto c : s1) {
                s1_temp += tolower(c);
            }
            for (auto c : s2) {
                s2_temp += tolower(c);
            }
            return s1_temp < s2_temp;
         });
    for (const auto& c : strings) {
        cout << c << ' ';
    }
    cout << endl;
    return 0;
}
