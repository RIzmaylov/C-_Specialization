#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class ReversibleString {
public:
    ReversibleString() {}
    ReversibleString(const string& some_string) {
        s = some_string;
    }
    string ToString() const {
        return s;
    }
    void Reverse() {
        string temp;
        for (int i = s.size() - 1; i >= 0; --i) {
            temp += s[i];
        }
        s = temp;
    }
private:
    string s;
};

int main() {
  ReversibleString s("live");
  s.Reverse();
  cout << s.ToString() << endl;

  s.Reverse();
  const ReversibleString& s_ref = s;
  string tmp = s_ref.ToString();
  cout << tmp << endl;

  ReversibleString empty;
  cout << '"' << empty.ToString() << '"' << endl;

  return 0;
}


