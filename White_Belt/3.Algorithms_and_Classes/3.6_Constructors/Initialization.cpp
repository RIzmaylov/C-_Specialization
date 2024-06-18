#include <iostream>
#include <vector>

/*
Определите тип Incognizable, для которого следующий код будет корректен:
*/
using namespace std;

class Incognizable {
public:
    Incognizable() {}
    Incognizable(int num) { data.push_back(num); }
    Incognizable(int num1, int num2) { data.push_back(num1); data.push_back(num2); }
private:
    vector<int> data;
};

int main() {
  Incognizable a;
  Incognizable b = {};
  Incognizable c = {0};
  Incognizable d = {0, 1};
  return 0;
}