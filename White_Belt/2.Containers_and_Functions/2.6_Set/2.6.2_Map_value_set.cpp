#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>

using namespace std;

set<string> BuildMapValuesSet(const map<int, string> & m) {
    set<string> temp;
    for (auto c : m) {
        temp.insert(c.second);
    }
    return temp;
}


