/*
Условие
В стандартном потоке дана одна строка, состоящая из N + 1 целых чисел. Первым числом идёт само число N. 
Далее следуют ещё N чисел, обозначим их за массив A. Между собой числа разделены пробелом.

Отсортируйте массив А по модулю и выведите его в стандартный поток.

Ограничения
0 <= N <= 1000
-1000000 <= A[i] <= 1000000

Примеры
stdin       stdout

2 -4 3      3 -4

3 1 -3 2    1 2 -3

 
Подсказка
функция sort дополнительно принимает третий аргумент
*/
#include <iostream>
#include <vector>
#include <algorithm>

std::vector<int> ReadNums(int cnt_nums) {
    std::vector<int> result;
    while (cnt_nums--) {
        int num = 0;
        std::cin >> num;
        result.push_back(num);
    }
    return result;
}

void PrintVec(const std::vector<int>& vec) {
    for(const auto& i : vec) {
        std::cout << i << ' ';
    }
}

int main() {
    int cnt;
    std::cin >> cnt;
    std::vector<int> res = ReadNums(cnt);
    PrintVec(res);
    std::cout << std::endl;
    std::sort(begin(res), end(res), [](int& x1, int& x2) { return std::abs(x1) < std::abs(x2); } );
    PrintVec(res);
    return 0;
}