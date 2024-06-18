/*
Реализуйте класс для человека, поддерживающий историю изменений человеком своих фамилии и имени.

Считайте, что в каждый год может произойти не более одного изменения фамилии и не более одного изменения имени. 
При этом с течением времени могут открываться всё новые факты из прошлого человека, поэтому года́ в 
последовательных вызовах методов ChangeLastName и ChangeFirstName не обязаны возрастать.

Гарантируется, что все имена и фамилии непусты.

Строка, возвращаемая методом GetFullName, должна содержать разделённые одним пробелом имя и фамилию человека 
по состоянию на конец данного года.

Если к данному году не случилось ни одного изменения фамилии и имени, верните строку "Incognito".

Если к данному году случилось изменение фамилии, но не было ни одного изменения имени, верните 
"last_name with unknown first name".

Если к данному году случилось изменение имени, но не было ни одного изменения фамилии, верните 
"first_name with unknown last name".
*/

#include <iostream>
#include <vector>
#include <map>

class Person {
public:
  void ChangeFirstName(int year, const std::string& first_name) {
    // добавить факт изменения имени на first_name в год year
    names[year] = first_name;
  }
  void ChangeLastName(int year, const std::string& last_name) {
    // добавить факт изменения фамилии на last_name в год year
    surnames[year] = last_name;
  }
  std::string GetFullName(int year) {
    // получить имя и фамилию по состоянию на конец года year
    auto it_name = names.upper_bound(year);
    auto it_surname = surnames.upper_bound(year);
    if (it_name == names.begin() && it_surname == surnames.begin()) {
        return "Incognito";
    }
    std::string first, last;
    if (it_name != names.begin()) {
        first = (*(--it_name)).second;
    }
    if (it_surname != surnames.begin()) {
        last = (*(--it_surname)).second;
    }
    if (first.empty()) return last + " with unknown first name";
    if (last.empty()) return first + " with unknown last name";
    return first + ' ' + last;
  }
private:
    // приватные поля
    std::map<int, std::string> names;
    std::map<int, std::string> surnames;
};

int main() {
//   Person person;
  
//   person.ChangeFirstName(1965, "Polina");
//   person.ChangeLastName(1967, "Sergeeva");
//   for (int year : {1900, 1965, 1990}) {
//     std::cout << person.GetFullName(year) << std::endl;
//   }
  
//   person.ChangeFirstName(1970, "Appolinaria");
//   for (int year : {1969, 1970}) {
//     std::cout << person.GetFullName(year) << std::endl;
//   }
  
//   person.ChangeLastName(1968, "Volkova");
//   for (int year : {1969, 1970}) {
//     std::cout << person.GetFullName(year) << std::endl;
//   }
  
  return 0;
}