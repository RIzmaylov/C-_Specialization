#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;


map<char, int> BuildCharCounters(string word) {
    map<char, int> char_counts;
    for (auto c : word) {
        char_counts[c]++;
    }
    return char_counts;
}

int main() {
    int N;
    cin >> N;
    while (N) {
        string word1, word2;
        cin >> word1 >> word2;
        cout << (BuildCharCounters(word1) == BuildCharCounters(word2) ? "YES" : "NO") << endl;

        --N;
    }

    return 0;
}
