#include <iostream>
#include <set>
#include <map>
#include <algorithm>

std::set<std::string> BuildMapValuesSet(const std::map<int, std::string>& m) {
    std::set<std::string> res;
    for (const auto& [key, value] : m)
    {
        res.insert(value);
    }
    return res;
}
std::set<std::string> BuildMapValuesSet2(const std::map<int, std::string>& m)
{
    std::set<std::string> result;
    std::transform(m.begin(), m.end(), std::inserter(result, result.begin()), [](const auto& pair)
    {
       return pair.second;
    });
    return result;
}

int main() {
    std::set<std::string> values = BuildMapValuesSet2({
        {1, "odd"},
        {2, "even"},
        {3, "odd"},
        {4, "even"},
        {5, "odd"}
    });

    for (const std::string& value : values) {
        std::cout << value << std::endl;
    }
    return 0;
}