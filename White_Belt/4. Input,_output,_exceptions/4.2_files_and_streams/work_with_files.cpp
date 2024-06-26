#include <iostream>
#include <fstream>
#include <iomanip>
/*
В этом задании вам предстоит написать две небольшие программы. 
Каждый пункт - отдельная задача, решение отправляйте в поле с соответствующим номером.

Часть 1
Ваша программа должна считать содержимое файла input.txt и напечатать его на экран без изменений. 
Гарантируется, что содержимое файла input.txt заканчивается переводом строки.

Пример
-----------
input.txt

Keep calm
and
learn C++
-----------
stdout

Keep calm
and
learn C++
-----------
*/
using namespace std;


// void CreateFile(const string& name, const string& text) {
//     ofstream output(name, ios::app);
//     output << text << endl;
// }

void PrintFile(const string& name) {
    ifstream input(name);
    string out_text;
    if (input)
        while(getline(input, out_text)) {
            cout << out_text << endl;
        }
    else cout << "error!!!" << endl;
}

int main() {
    // string text = "Keep calm\n and\n learn C++\n";
    string name = "D:/Users/izmaylov.r/Desktop/Specialization/C_plus_plus_Specialization/White_Belt/4. Input,_output,_exceptions/4.2_files_and_streams/input.txt";
    // CreateFile(text, name);
    PrintFile(name);
    return 0;
}