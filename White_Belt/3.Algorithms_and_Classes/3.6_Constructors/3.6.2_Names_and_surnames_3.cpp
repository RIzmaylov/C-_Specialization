#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_set>

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

bool ElderThanBirth (const map<int, string>& names, int year) {
    for (const auto& item : names) {
        if (item.first <= year) {
            return true;
        } else {
            return false;
        }
    }
}

class Person {
public:
    Person(const string& first, const string& second, int birth) {
        first_names[birth] = first;
        last_names[birth] = second;
    }
  void ChangeFirstName(int year, const string& first_name) {
      if (ElderThanBirth(first_names, year)) first_names[year] = first_name;
  }
  void ChangeLastName(int year, const string& last_name) {
      if (ElderThanBirth(first_names, year)) last_names[year] = last_name;
  }

  string GetFullNameWithHistory(int year) const {
    if (!ElderThanBirth(first_names, year)) return "No person";
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
    if (!ElderThanBirth(first_names, year)) return "No person";
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
    map<int, string> first_names;
    map<int, string> last_names;
};

int main() {
  Person person("Polina", "Sergeeva", 1960);
  for (int year : {1959, 1960}) {
    cout << person.GetFullNameWithHistory(year) << endl;
  }

  person.ChangeFirstName(1965, "Appolinaria");
  person.ChangeLastName(1967, "Ivanova");
  for (int year : {1965, 1967}) {
    cout << person.GetFullNameWithHistory(year) << endl;
  }

  return 0;
}


