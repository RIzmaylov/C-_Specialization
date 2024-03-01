#include <iostream>
#include <set>
#include <map>

void AddSyn(std::map<std::string, std::set<std::string>>& dict, const std::string& word1, const std::string& word2) {
    dict[word1].insert(word2);
    dict[word2].insert(word1);
}

int CountSyns(const std::map<std::string, std::set<std::string>>& dict, const std::string& word) {
    if (dict.count(word)) {
        return dict.at(word).size();
    }
    return 0;
}

bool CheckSyn(const std::map<std::string, std::set<std::string>>& dict, 
                const std::string& word1, const std::string& word2) {
    if (dict.count(word1) && dict.at(word1).count(word2)) return true;
    return false;
}

void ParseReq(const std::string& req, std::map<std::string, std::set<std::string>>& dict) {
    if (req == "ADD") {
        std::string word1, word2;
        std::cin >> word1 >> word2;
        AddSyn(dict, word1, word2);
    } else if (req == "COUNT") {
        std::string word;
        std::cin >> word;
        std::cout << CountSyns(dict, word) << std::endl;
    } else if (req == "CHECK") {
        std::string word1, word2;
        std::cin >> word1 >> word2;
        std::cout << (CheckSyn(dict, word1, word2) ? "YES" : "NO") << std::endl;
    }
}

int main() {
    int Q = 0;
    std::cin >> Q;
    std::map<std::string, std::set<std::string>> dict;
    while(Q--) {
        std::string req;
        std::cin >> req;
        ParseReq(req, dict);
    }
    return 0;
}