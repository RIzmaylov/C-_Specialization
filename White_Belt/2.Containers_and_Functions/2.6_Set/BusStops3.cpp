#include <iostream>
#include <set>
#include <map>
#include <vector>

int main() {
    int Q;
    std::cin >> Q;
    std::map<std::set<std::string>, int> routes;
    int i = 0;
    while(Q--) {
        int N;
        std::cin >> N;
        std::set<std::string> rout;
        while(N--) {
            std::string stop;
            std::cin >> stop;
            rout.insert(stop);
        }
        if (routes.count(rout)) {
            std::cout << "Already exists for " << routes.at(rout) << '\n';
        } else {
            routes[rout] = ++i;
            std::cout << "New bus " << i << '\n';
        }
    }
    return 0;
}
