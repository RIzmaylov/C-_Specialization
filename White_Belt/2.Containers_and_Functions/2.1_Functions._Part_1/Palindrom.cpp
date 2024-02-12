#include <iostream>

/*
Напишите функцию, которая
- называется IsPalindrom
- возвращает bool
- принимает параметр типа string и возвращает, является ли переданная строка палиндромом

Палиндром - это слово или фраза, которые одинаково читаются слева направо и справа налево. 
Пустая строка является палиндромом.

Аргумент функции        Результат

madam                   true

gentleman               false

X                       true

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

int main() {
    std::cout << std::boolalpha << IsPalindrom("X");
    return 0;
}