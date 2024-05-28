#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;


void Print(const vector<int>& v) {
    for (const auto& c : v) {
        cout << c << ' ';
    }
    cout << endl;
}

int main()
{
    int N = 0;
    cin >> N;
    vector<int> nums;

    while (N--) {
        int k;
        cin >> k;
        nums.push_back(k);
    }
    sort(nums.begin(), nums.end(), [](int& x ,int& y) {return abs(x) < abs(y);} );
    Print(nums);
    return 0;
}
