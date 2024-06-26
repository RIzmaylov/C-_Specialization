#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ifstream input("D:/Users/izmaylov.r/Desktop/Specialization/C_plus_plus_Specialization/White_Belt/4. Input,_output,_exceptions/4.2_files_and_streams/input.txt");
    if (input) {
        string temp;
        while (getline(input, temp))
            cout << temp << endl;
    }

    return 0;
}

