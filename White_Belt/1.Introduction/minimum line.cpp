#include <algorithm>
#include <iostream>
#include <string>

auto main() -> int
{
    std::string a, b, c;
    std::cin >> a >> b >> c;
    std::cout << std::min({ a, b, c });
}
