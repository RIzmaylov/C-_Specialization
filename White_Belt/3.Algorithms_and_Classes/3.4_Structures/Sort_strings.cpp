/*
Реализуйте класс, поддерживающий набор строк в отсортированном порядке. Класс должен содержать два публичных метода:
*/
#include <iostream>
#include <vector>
#include <set>

class SortedStrings {
public:
    void AddString(const std::string& s) {
        strings.insert(s);
    }
    std::vector<std::string> GetSortedStrings() {
        return {strings.begin(), strings.end()};
    }
private:
    std::multiset<std::string> strings;
};

// void PrintSortedStrings(SortedStrings& strings) {
//   for (const std::string& s : strings.GetSortedStrings()) {
//     std::cout << s << " ";
//   }
//   std::cout << std::endl;
// }

// int main() {
//   SortedStrings strings;
  
//   strings.AddString("first");
//   strings.AddString("third");
//   strings.AddString("second");
//   PrintSortedStrings(strings);
  
//   strings.AddString("second");
//   PrintSortedStrings(strings);
  
//   return 0;
// }