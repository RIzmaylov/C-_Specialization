#include <iostream>
#include <string>

using namespace std;

bool IsPalindrom (string someS) {
    if (someS.empty()) return true;
    for (int i = 0, j = someS.size()-1; someS[i] == someS[j]; ++i, --j) {
        if (i >= j) return true;
    }
    return false;
}
int main() {
    return 0;
}

