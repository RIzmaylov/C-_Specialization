#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool IsPalindrom2 (string someS) {
    for (int i = 0; i < someS.size() / 2; ++i) {
        if (someS[i] != someS[someS.size() - 1 - i]) return false;
    }
    return true;
}

vector<string> PalindromFilter (vector<string> words, int minLength) {
    vector<string> palindroms;
    for (auto s : words) {
        if (IsPalindrom2(s) && s.size() >= minLength) palindroms.push_back(s);
    }
    return palindroms;
}

int main() {
//    vector<string> vec = PalindromFilter({"weew", "bro", "code"}, 4);
//    for (auto s : vec) {
//        cout << s << " ";
//    }
    return 0;
}

