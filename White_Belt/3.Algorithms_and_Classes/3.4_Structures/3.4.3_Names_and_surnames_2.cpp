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

class Person {
public:
  void ChangeFirstName(int year, const string& first_name) {
      first_names[year] = first_name;
  }
  void ChangeLastName(int year, const string& last_name) {
      last_names[year] = last_name;
  }

  string GetFullNameWithHistory(int year) {
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
  string GetFullName(int year) {
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
  Person person;

  person.ChangeFirstName(1965, "Polina");
  person.ChangeLastName(1967, "Sergeeva");
  for (int year : {1900, 1965, 1990}) {
    cout << person.GetFullNameWithHistory(year) << endl;
  }

  person.ChangeFirstName(1970, "Appolinaria");
  for (int year : {1969, 1970}) {
    cout << person.GetFullNameWithHistory(year) << endl;
  }

  person.ChangeLastName(1968, "Volkova");
  for (int year : {1969, 1970}) {
    cout << person.GetFullNameWithHistory(year) << endl;
  }

  person.ChangeFirstName(1990, "Polina");
  person.ChangeLastName(1990, "Volkova-Sergeeva");
  cout << person.GetFullNameWithHistory(1990) << endl;

  person.ChangeFirstName(1966, "Pauline");
  cout << person.GetFullNameWithHistory(1966) << endl;

  person.ChangeLastName(1960, "Sergeeva");
  for (int year : {1960, 1967}) {
    cout << person.GetFullNameWithHistory(year) << endl;
  }

  person.ChangeLastName(1961, "Ivanova");
  cout << person.GetFullNameWithHistory(1967) << endl;

  return 0;
}


