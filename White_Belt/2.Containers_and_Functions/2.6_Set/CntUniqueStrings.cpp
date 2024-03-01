#include <iostream>
#include <set>

int main() {
    int N;
    std::cin >> N;
    std::set<std::string> uniqueStrings;
    std::string s;
    while(N--) {
        std::cin >> s;
        uniqueStrings.insert(s);
    }
    std::cout << uniqueStrings.size() << std::endl;
    return 0;
}