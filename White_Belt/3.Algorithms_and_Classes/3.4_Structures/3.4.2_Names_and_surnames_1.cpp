#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

class Person {
public:
  void ChangeFirstName(int year, const string& first_name) {
      names[year] = first_name;
  }
  void ChangeLastName(int year, const string& last_name) {
      surnames[year] = last_name;
  }

  string GetFullName(int year) {
    string result;
    if (names.count(year) && surnames.count(year)) result = names[year] + ' ' + surnames[year];
    else if (names.count(year) && !surnames.count(year)) {
        int prev = FindPrev(surnames, year);
        if (prev) result = names[year] + ' ' + surnames[prev];
        else result = names[year] + " with unknown last name";
    } else if (!names.count(year) && surnames.count(year)){
        int prev = FindPrev(names, year);
        if (prev) result = names[prev] + ' ' + surnames[year];
        else result = surnames[year] + " with unknown first name";
    } else {
        int prevFirst = FindPrev(names, year);
        int prevLast = FindPrev(surnames, year);
        if (prevFirst && prevLast) {
            result = names[prevFirst] + ' ' + surnames[prevLast];
        } else if (!prevFirst && prevLast) result = surnames[prevLast] + " with unknown first name";
        else if (prevFirst && !prevLast) result = names[prevFirst] + " with unknown last name";
        else result = "Incognito";
    }
    return result;
  }
private:
    int FindPrev(const map<int, string>& n, int year) {
        int res = 0;
        for (const auto& c : n) {
            if (c.first < year) res = c.first;
            else break;
        }
        return res;
    }
    map<int, string> names;
    map<int, string> surnames;
};

int main() {
//  Person person;
//
//  person.ChangeFirstName(1965, "Polina");
//  person.ChangeLastName(1967, "Sergeeva");
//  for (int year : {1900, 1965, 1990}) {
//    cout << person.GetFullName(year) << endl;
//  }
//
//  person.ChangeFirstName(1970, "Appolinaria");
//  for (int year : {1969, 1970}) {
//    cout << person.GetFullName(year) << endl;
//  }
//
//  person.ChangeLastName(1968, "Volkova");
//  for (int year : {1969, 1970}) {
//    cout << person.GetFullName(year) << endl;
//  }
//  person.ChangeLastName(1966, "KKK");
//  person.ChangeFirstName(1966, "Alina");
//  person.ChangeFirstName(1969, "Tonya");
//  for (int year : {1966, 1967, 1968, 1970, 1964, 1969}) {
//    cout << person.GetFullName(year) << endl;
//  }
////  person.ChangeLastName(1941, "Volkova1");
////  person.ChangeLastName(1944, "Volkova2");
////  person.ChangeLastName(1946, "Volkova3");
////  person.ChangeLastName(1948, "Volkova4");
////  for (int year : {1942, 1944, 1946, 1648, 1965}) {
////    cout << person.GetFullName(year) << endl;
////  }
//  person.ChangeFirstName(1941, "Tonya1");
//  person.ChangeFirstName(1944, "Tonya2");
//  person.ChangeFirstName(1946, "Tonya3");
//  person.ChangeFirstName(1948, "Tonya4");
//  for (int year : {1942, 1944, 1946, 1948, 1965}) {
//    cout << person.GetFullName(year) << endl;
//  }
  return 0;
}


