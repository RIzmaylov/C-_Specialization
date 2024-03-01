#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>

using namespace std;

int main() {
    map<string,set<string>> dict;
    int N;
    cin >> N;

    while (N--) {
        string command;
        cin >> command;

        if (command == "ADD") {
            string word1, word2;
            cin >> word1 >> word2;
            dict[word1].insert(word2);
            dict[word2].insert(word1);
//            for (auto c : dict) {
//                cout << c.first << ' ';
//                for (auto i : c.second) {
//                    cout << i << ' ';
//                }
//                cout << endl;
//            }
        } else if (command == "COUNT") {
            string word;
            cin >> word;
            if (dict.count(word)) cout << dict[word].size() << endl;
            else cout << 0 << endl;
        } else if (command == "CHECK") {
            string word1, word2;
            cin >> word1 >> word2;
            if (dict.count(word1) && dict[word1].count(word2) || dict.count(word2) && dict[word2].count(word1)) {
                cout << "YES" << endl;
            } else cout << "NO" << endl;
        }
    }

    return 0;
}

