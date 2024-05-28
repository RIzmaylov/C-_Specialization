/*
Условие
В стандартном потоке дана одна строка, состоящая из числа N и следующих за ним N строк S. 
Между собой число и строки разделены пробелом.

Отсортируйте строки S в лексикографическом порядке по возрастанию, игнорируя регистр букв, 
и выведите их в стандартный поток вывода.

Ограничения
0 <= N <= 1000
1 <= |S| <= 15

Каждая строка S[i] может состоять из следующих символов: [0-9,a-z,A-Z]

Примеры
stdin       stdout

2 q A       A q

3 a C b     a b C

 
Подсказка
Обратите внимание на функцию tolower.
*/

#include <iostream>
#include <vector>
#include <algorithm>

std::vector<std::string> ReadWords(int cnt) {
    std::vector<std::string> res;
    while(cnt--) {
        std::string tempS;
        std::cin >> tempS;
        res.push_back(tempS);
    }
    return res;
}

void PrintVecString(const std::vector<std::string>& vec) {
    for(const auto& i : vec) {
        std::cout << i << ' ';
    }
}

std::string ToLower(std::string s) {
    std::string res;
    for (const auto& c : s) {
        res.push_back(tolower(c));
    }
    return res;
}

int main() {
    int cnt = 0;
    std::cin >> cnt;
    std::vector<std::string> words = ReadWords(cnt);
    // PrintVecString(words);
    // std::cout << std::endl;
    std::sort(begin(words), end(words), [](std::string& s1, std::string& s2) { 
        return ToLower(s1) < ToLower(s2);
    });
    PrintVecString(words);

    return 0;
}