#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h>

using namespace std;

/*
Определите структуру «Студент» со следующими полями: имя, фамилия, день, месяц и год рождения. 
Создайте вектор из таких структур, заполните его из входных данных и затем по запросам выведите нужные поля.

Формат ввода

Первая строка содержит одно целое число N от 0 до 10000 — число студентов.

Далее идут N строк, каждая из которых содержит две строки длиной от 1 до 15 символов — имя и фамилию очередного студента,
 и три целых числа от 0 до 1000000000 — день, месяц и год рождения.

Следующая строка содержит одно целое число M от 0 до 10000 — число запросов.

Следующие M строк содержат строку длиной от 1 до 15 символов — запрос, 
и целое число от 0 до 1000000000 — номер студента (нумерация начинается с 1).

Формат вывода

Для запроса вида name K, где K от 1 до N, выведите через пробел имя и фамилию K-го студента.

Для запроса вида date K, где K от 1 до N, выведите через точку день, месяц и год рождения K-го студента.

Для остальных запросов выведите bad request.

 

Пример ввода

3
Ivan Ivanov 1 1 1901
Petr Petrox 2 2 1902
Alexander Sidorov 3 3 1903
3
name 1
date 3
mark 5
 

Пример вывода

Ivan Ivanov
3.3.1903
bad request
*/
struct Student {
    string first_name;
    string last_name;
    int day;
    int month;
    int year;
};

bool StringIsDigit (const string& s) {
    for (size_t i = 0; i < s.size(); ++i) {
        if (isdigit(s[i]) == false) {
            return false;
        }
        return true;
    }
}

void OutputFunc(const vector<Student>& vec, const string& request) {
    string temp_req;
    string temp_num;
    size_t iter = 0;
    for (; iter < request.size(); ++iter) {
        if (request[iter] != ' ') {
            temp_req += request[iter];
            continue;
        }
         else if (request[iter] == ' ') {
            iter++;
            break;
         }
    }
    for (; iter < request.size(); ++iter) {
        temp_num += request[iter];
    }
    int K = 0;
    if (StringIsDigit(temp_num)) {
        K = atoi(temp_num.c_str());
    }
    if (temp_req == "name" && K > 0 && K <= vec.size()) {
        cout << vec[K-1].first_name << ' ' << vec[K-1].last_name << endl;
    } else if (temp_req == "date" && K > 0 && K <= vec.size()) {
       cout << vec[K-1].day << '.' << vec[K-1].month << '.' << vec[K-1].year << endl;

    } else {
        cout << "bad request" << endl;
    }
}

int main()
{
    vector<Student> students_list;
    int N;
    cin >> N;

    for (int i = 0; i < N; ++i) {
        Student temp;
        cin >> temp.first_name >> temp.last_name >> temp.day >> temp.month >> temp.year;
        students_list.push_back(temp);
    }
    int M;
    cin >> M;
    cin.ignore(1);
    for (int i = 0; i < M; ++i) {
        string temp_s;
        getline(cin, temp_s);
        OutputFunc(students_list, temp_s);
    }
    return 0;
}
