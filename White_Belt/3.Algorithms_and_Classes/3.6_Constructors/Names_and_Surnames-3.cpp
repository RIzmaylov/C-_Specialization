#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_set>
/*
Дополните класс Person из задачи «Имена и фамилии — 2» конструктором, 
позволяющим задать имя и фамилию человека при рождении, а также сам год рождения. 
Класс не должен иметь конструктора по умолчанию.

При получении на вход года, который меньше года рождения:

методы GetFullName и GetFullNameWithHistory должны отдавать "No person";

методы ChangeFirstName и ChangeLastName должны игнорировать запрос.

Кроме того, необходимо объявить константными все методы, которые по сути ими являются.

Вывод
No person
Polina Sergeeva
Appolinaria (Polina) Sergeeva
Appolinaria (Polina) Ivanova (Sergeeva)
*/
using namespace std;

string FindNameByYear(const map<int, string>& names, int year) {
  string name;

  for (const auto& item : names) {
    if (item.first <= year) {
      name = item.second;
    } else {
      break;
    }
  }

  return name;
}

vector<string> FindNameBeforeYear(const map<int, string>& names, int year, string some_string) {
  vector<string> uniqueNames;
  vector<string> uniqueNames2;
  for (const auto& item : names) {
    if (item.first < year) {
      uniqueNames.push_back(item.second);
    } else {
      break;
    }
  }
  if (!uniqueNames.empty()) uniqueNames2.push_back(uniqueNames[0]);
  for (size_t i = 1; i < uniqueNames.size(); ++i) {
    if (uniqueNames[i] != uniqueNames[i - 1]) {
        uniqueNames2.push_back(uniqueNames[i]);
    }
  }
  if (!uniqueNames2.empty() && uniqueNames2[uniqueNames2.size()-1] == some_string ) uniqueNames2.pop_back();
  return uniqueNames2;
}

class Person {
public:
  Person(const std::string& name, const std::string& surname, int year) 
            : birthname(name), birth_surname(surname), birth_year(year) {
              first_names[year] = name;
              last_names[year] = surname;
            }

  void ChangeFirstName(int year, const string& first_name) {
      if (year > birth_year) first_names[year] = first_name;
  }
  void ChangeLastName(int year, const string& last_name) {
      if (year > birth_year) last_names[year] = last_name;
  }

  string GetFullNameWithHistory(int year) const {
    if (year < birth_year) return "No person";

    const string first_name = FindNameByYear(first_names, year);
    const string last_name = FindNameByYear(last_names, year);
    string before_first_name;
    string before_last_name;
    vector<string> befors_first_names = FindNameBeforeYear(first_names, year, first_name);
    vector<string> befors_last_names = FindNameBeforeYear(last_names, year, last_name);
    for (int i = befors_first_names.size() - 1; i >= 0; --i) {
        before_first_name = before_first_name + befors_first_names[i] + ", ";
    }
    if (!before_first_name.empty()) {
            before_first_name.pop_back();
            before_first_name.pop_back();
    }
    for (int i = befors_last_names.size() - 1; i >= 0; --i) {
        before_last_name = before_last_name + befors_last_names[i] + ", ";
    }
    if (!before_last_name.empty()) {
            before_last_name.pop_back();
            before_last_name.pop_back();
    }
    if (!before_last_name.empty()) before_last_name = " (" + before_last_name + ')';
    if (!before_first_name.empty()) before_first_name = " (" + before_first_name + ')';

    if (first_name.empty() && last_name.empty()) {
      return "Incognito";

    } else if (first_name.empty()) {
      return last_name + before_last_name + " with unknown first name";

    } else if (last_name.empty()) {
      return first_name + before_first_name + " with unknown last name";

    } else {
      return first_name + before_first_name + " " + last_name + before_last_name;
    }
  }
  string GetFullName(int year) const {
    if (year < birth_year) return "No person";

    const string first_name = FindNameByYear(first_names, year);
    const string last_name = FindNameByYear(last_names, year);

    if (first_name.empty() && last_name.empty()) {
      return "Incognito";

    } else if (first_name.empty()) {
      return last_name + " with unknown first name";

    } else if (last_name.empty()) {
      return first_name + " with unknown last name";

    } else {
      return first_name + " " + last_name;
    }
  }

private:
    std::map<int, std::string> first_names;
    std::map<int, std::string> last_names;
    std::string birthname, birth_surname;
    int birth_year = 0;
};

int main() {
  Person person("Polina", "Sergeeva", 1960);
  for (int year : {1959, 1960}) {
    std::cout << person.GetFullNameWithHistory(year) << std::endl;
  }
  
  person.ChangeFirstName(1965, "Appolinaria");
  person.ChangeLastName(1967, "Ivanova");
  for (int year : {1965, 1967}) {
    std::cout << person.GetFullNameWithHistory(year) << std::endl;
  }

  return 0;
}