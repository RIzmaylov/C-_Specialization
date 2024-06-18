/*
Дополните класс из предыдущей задачи «Имена и фамилии — 1» методом GetFullNameWithHistory:

В отличие от метода GetFullName, метод GetFullNameWithHistory должен вернуть 
не только последние имя и фамилию к концу данного года, но ещё и все предыдущие имена и фамилии в 
обратном хронологическом порядке. Если текущие факты говорят о том, что человек два раза подряд изменил 
фамилию или имя на одно и то же, второе изменение при формировании истории нужно игнорировать.

Для лучшего понимания формата см. примеры.
*/
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <set>

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
  std::string GetFullNameWithHistory(int year) {
    // получить все имена и фамилии по состоянию на конец года year
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
    
    std::string old_names = GetNames(names, year, first);
    std::string old_surnames = GetNames(surnames, year, last);
    if (!old_names.empty()) old_names += ' ';
    if (!old_surnames.empty()) old_surnames += ' ';
    old_names = ' ' + old_names;
    old_surnames = ' ' + old_surnames;

    if (first.empty()) return last + old_surnames + "with unknown first name";
    if (last.empty()) return first + old_names + "with unknown last name";
    return first + old_names + last + old_surnames;
  }
private:
    // приватные поля
    std::string GetNames(const std::map<int, std::string>& names, int year, const std::string& current_name) {
        std::vector<std::string> result_vec;
        // if (!current_name.empty()) result_vec.push_back(current_name);
        std::string result;
        for (const auto& name : names) {
            if (name.first > year) break;
            if (result_vec.empty() && name.second != current_name) {
                result_vec.push_back(name.second);
                result = name.second + ", " + result;
            }
            if (!result_vec.empty() && result_vec.back() != name.second) {
                result_vec.push_back(name.second);
                result = name.second + ", " + result;
            }
        }
        if (!result.empty()) {
            result.pop_back();
            result.pop_back();
            result = '(' + result + ')';
        }
        return result;
    }
    std::map<int, std::string> names;
    std::map<int, std::string> surnames;
};

int main() {
#pragma region 
//   Person person;

//   person.ChangeFirstName(1900, "Eugene");
//   person.ChangeLastName(1900, "Sokolov");
//   person.ChangeLastName(1910, "Sokolov");
//   person.ChangeFirstName(1920, "Evgeny");
//   person.ChangeLastName(1930, "Sokolov");
//   std::cout << person.GetFullNameWithHistory(1940) << std::endl;
//   // Evgeny (Eugene) Sokolov

//   return 0;
// #pragma endregion
#pragma region 
    Person person;
  
  person.ChangeFirstName(1965, "Polina");
  person.ChangeLastName(1967, "Sergeeva");
  for (int year : {1900, 1965, 1990}) {
    std::cout << person.GetFullNameWithHistory(year) << std::endl;
  }
  
  person.ChangeFirstName(1970, "Appolinaria");
  for (int year : {1969, 1970}) {
    std::cout << person.GetFullNameWithHistory(year) << std::endl;
  }
  
  person.ChangeLastName(1968, "Volkova");
  for (int year : {1969, 1970}) {
    std::cout << person.GetFullNameWithHistory(year) << std::endl;
  }
  
  person.ChangeFirstName(1990, "Polina");
  person.ChangeLastName(1990, "Volkova-Sergeeva");
  std::cout << person.GetFullNameWithHistory(1990) << std::endl;
  
  person.ChangeFirstName(1966, "Pauline");
  std::cout << person.GetFullNameWithHistory(1966) << std::endl;
  
  person.ChangeLastName(1960, "Sergeeva");
  for (int year : {1960, 1967}) {
    std::cout << person.GetFullNameWithHistory(year) << std::endl;
  }
  
  person.ChangeLastName(1961, "Ivanova");
  std::cout << person.GetFullNameWithHistory(1967) << std::endl;
  
  return 0;

// Incognito
// Polina with unknown last name
// Polina Sergeeva
// Polina Sergeeva
// Appolinaria (Polina) Sergeeva
// Polina Volkova (Sergeeva)
// Appolinaria (Polina) Volkova (Sergeeva)
// Polina (Appolinaria, Polina) Volkova-Sergeeva (Volkova, Sergeeva)
// Pauline (Polina) with unknown last name
// Sergeeva with unknown first name
// Pauline (Polina) Sergeeva
// Pauline (Polina) Sergeeva (Ivanova, Sergeeva)
#pragma endregion

}