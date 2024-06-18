#include <iostream>
// Реализуйте класс ReversibleString, хранящий строку и поддерживающий методы Reverse для переворота строки и 
// ToString для получения строки. 

// Вывод
// evil
// live
// ""

class ReversibleString {
public:
    ReversibleString(const std::string& s) : data(s) {}
    ReversibleString() {}
    
    std::string ToString() const { return data; }

    void Reverse() {
        std::string new_data;
        for (int i = data.length() - 1; i >= 0; --i) {
            new_data += data[i];
        }
        data = new_data;
    }
private:
    std::string data;
};

int main() {
  ReversibleString s("live");
  s.Reverse();
  std::cout << s.ToString() << std::endl;
  
  s.Reverse();
  const ReversibleString& s_ref = s;
  std::string tmp = s_ref.ToString();
  std::cout << tmp << std::endl;
  
  ReversibleString empty;
  std::cout << '"' << empty.ToString() << '"' << std::endl;
  
  return 0;
}