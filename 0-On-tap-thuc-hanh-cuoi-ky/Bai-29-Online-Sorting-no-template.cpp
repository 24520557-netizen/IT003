#include <iostream>
#include <map>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    map<long long, int, greater<long long>> tanSuat;

    long long val;
    while (cin >> val) {
        if (val == 0) break;
        tanSuat[val]++;
    }
    for (auto it : tanSuat) {
        cout << it.first << " " << it.second << "\n";
    }
    return 0;
}