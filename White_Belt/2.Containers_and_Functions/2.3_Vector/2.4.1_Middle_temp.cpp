#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int N, sum = 0;
    cin >> N;
    vector<int> temps(N);
    for (int& c : temps) {
        cin >> c;
        sum += c;
    }
    int countTemps = temps.size();
    int mid = sum / countTemps;
    vector<int> TempsHigherThanMid;
    for (int i = 0; i < countTemps; ++i) {
        if (temps[i] > mid) TempsHigherThanMid.push_back(i);
    }
    cout << TempsHigherThanMid.size() << endl;
    for (auto i : TempsHigherThanMid) {
        cout << i << ' ';
    }
    return 0;
}
