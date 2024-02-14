#include <iostream>
#include <vector>

/*
Напишите функцию MoveStrings, которая принимает два вектора строк, source и destination, 
и дописывает все строки из первого вектора в конец второго. 
После выполнения функции вектор source должен оказаться пустым.

Чтобы очистить содержимое вектора, надо вызвать у него метод clear:

vector<string> words = {"hey", "hi"};
words.clear();
// Теперь вектор words пуст
 

Пример

vector<string> source = {"a", "b", "c"};
vector<string> destination = {"z"};
MoveStrings(source, destination);
// source должен оказаться пустым
// destination должен содержать строки "z", "a", "b", "c" именно в таком порядке
*/

void MoveStrings(std::vector<std::string>& source, std::vector<std::string>& destination) {
    for (auto s : source) destination.push_back(s);

    source.clear();
}

int main() {
    std::vector<std::string> source = {"a", "b", "c"};
    std::vector<std::string> destination = {"z"};
    MoveStrings(source, destination);
    for (auto s : destination) {
        std::cout << s << ' ';
    }
    std::cout << std::endl;
    for (auto s : source) {
        std::cout << s << ' ';
    }
    
    return 0;
}