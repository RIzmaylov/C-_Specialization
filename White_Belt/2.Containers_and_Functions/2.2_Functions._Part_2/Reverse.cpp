#include <iostream>
#include <vector>

/*
Реализуйте функцию void Reverse(vector<int>& v), которая переставляет элементы вектора в обратном порядке.

Пример

vector<int> numbers = {1, 5, 3, 4, 2};
Reverse(numbers);
// numbers должен оказаться равен {2, 4, 3, 5, 1}
*/
void Swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

void Reverse(std::vector<int>& numbers) {
    size_t size = numbers.size();
    for (size_t i = 0; i < size / 2; i++)
    {
        Swap(numbers[i], numbers[size - 1 - i]);
    }
}

int main() {
    std::vector<int> numbers = {1, 5, 3, 4, 2};
    Reverse(numbers);
    for (auto i : numbers)
    {
        std::cout << i << ' ';
    }
    
    return 0;
}