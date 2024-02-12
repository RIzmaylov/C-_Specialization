#include <iostream>
#include <vector>

/*
Напишите функцию, которая
- называется PalindromFilter
- возвращает vector<string>
- принимает vector<string> words и int minLength и возвращает все строки из вектора words, 
    которые являются палиндромами и имеют длину не меньше minLength

Входной вектор содержит не более 100 строк, длина каждой строки не больше 100 символов.

Примеры
words               minLength   результат

abacaba, aba        5           abacaba

abacaba, aba        2           abacaba, aba

weew, bro, code     4           weew

На проверку пришлите файл с реализацией функции PalindromFilter. 
Ваш файл может содержать и другие функции, если они вам необходимы. 
В этой задаче ваша программа не обязана что-то считывать из stdin и 
записывать в stdout — тестирующая система будет вызывать вашу функцию PalindromFilter напрямую
*/

/**
 * Функция принимает строку и определяет палиндром ли слово
*/
bool IsPalindrom(const std::string& str) {
    for (int i = 0; i < str.length() / 2; ++i) {
        if (str[i] != str[str.length() - i - 1]) return false;
    }
    return true;
}

/**
 * Функция принимает вектор строк и находит в нем палиндромы длиной не меньше minLength
*/
std::vector<std::string> PalindromFilter(const std::vector<std::string>& words, const int minLength) {
    std::vector<std::string> result;
    result.reserve(words.size());
    for (auto &word : words) {
        if (word.length() >= minLength && IsPalindrom(word)) {
            result.push_back(word);
        }
    }
    return result;
}

int main() {
    std::vector<std::string> words = PalindromFilter({"weew", "bro", "code"}, 4);
    for (auto word : words) {
        std::cout << word << ' ';
    }
    return 0;
}