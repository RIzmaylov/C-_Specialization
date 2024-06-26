#include <iostream>
#include <fstream>
#include <iomanip>
/*
Часть 2
Снова считайте все содержимое файла input.txt, но на этот раз выведите его в файл output.txt . 
Точно так же гарантируется, что содержимое файла input.txt заканчивается переводом строки. 

Пример
-----------
input.txt

Keep calm
and
learn C++
-----------
output.txt

Keep calm
and
learn C++
*/
using namespace std;


void CreateFile(const string& name, const string& text) {
    ofstream output(name, ios::app);
    output << text << endl;
}

void PrintFile(const string& name) {
    ifstream input(name);
    string out_text;
    if (input)
        while(getline(input, out_text)) {
            cout << out_text << endl;
        }
    else cout << "error!!!" << endl;
}
void WriteFile(const string& name, const string& out_name) {
    ofstream output(out_name, ios::app);
    ifstream input(name);
    string out_text;
    if (input)
        while(getline(input, out_text)) {
            output << out_text << endl;
        }
    else cout << "error!!!" << endl;
}
int main() {
    // string text = "Keep calm\n and\n learn C++\n";
    string name = "D:/Users/izmaylov.r/Desktop/Specialization/C_plus_plus_Specialization/White_Belt/4. Input,_output,_exceptions/4.2_files_and_streams/input.txt";
    string out_name = "D:/Users/izmaylov.r/Desktop/Specialization/C_plus_plus_Specialization/White_Belt/4. Input,_output,_exceptions/4.2_files_and_streams/output.txt";
    // CreateFile(text, name);
    WriteFile(name, out_name);
    return 0;
}