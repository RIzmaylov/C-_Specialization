#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    vector<bool> people_queue;
    string command;
    int number_of_person;
    int count_operation = 0;

    cin >> count_operation;
    while (count_operation) {
        cin >> command;
        if (command == "WORRY") {
            cin >> number_of_person;
            people_queue[number_of_person] = true;
        } else if (command == "QUIET") {
            cin >> number_of_person;
            people_queue[number_of_person] = false;
        } else if (command == "COME") {
            cin >> number_of_person;
            if (number_of_person > 0) {
                while (number_of_person) {
                    people_queue.push_back(false);
                    --number_of_person;
                }
            } else {
                while (number_of_person) {
                    people_queue.pop_back();
                    ++number_of_person;
                }
            }
        } else if (command == "WORRY_COUNT") {
            int count_worry = 0;
            for (auto i : people_queue) {
                if (i) count_worry++;
            }
            cout << count_worry << endl;
        }
        --count_operation;
    }
    return 0;
}
