#include <iostream>
#include <vector>

/*
Реализуйте функцию vector<int> Reversed(const vector<int>& v), возвращающую копию вектора v, 
в которой числа переставлены в обратном порядке.

Пример

Вектор v            Результат функции

1, 5, 3, 4, 2       2, 4, 3, 5, 1
*/

std::vector<int> Reversed(const std::vector<int>& v) {
    std::vector<int> result;
    for (int i = v.size() - 1; i >= 0; i--)
    {
        result.push_back(v[i]);
    }
    return result;
} 

int main() {
    std::vector<int> vec = {1, 5, 3, 4, 2};
    std::vector<int> res = Reversed(vec);
    for (auto i : res)
    {
        std::cout << i << ' ';
    }
    
    return 0;
}