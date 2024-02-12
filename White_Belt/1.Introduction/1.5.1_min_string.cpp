#include <iostream>

using namespace std;

int main()
{
    string a, b, c;
    cin >> a >> b >> c;
    string minstr;
    a < b ? minstr = a : minstr = b;
    cout << (minstr < c ? minstr : c);
    return 0;
}

