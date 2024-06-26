#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ifstream input("input.txt");
    ofstream output("output.txt");
    if (input) {
        string temp;
        while (getline(input, temp))
            output << temp << endl;
    }

    return 0;
}


