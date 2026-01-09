#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Diem {
    int x, y;
};

bool quy_tac_sap_xep(Diem a, Diem b) {
    if (a.x != b.x) {
        return a.x < b.x; }
    return a.y > b.y;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<Diem> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i].x >> a[i].y;
    }
    sort(a.begin(), a.end(), quy_tac_sap_xep);
    for (int i = 0; i < n; i++) {
        cout << a[i].x << " " << a[i].y << "\n";
    }
    return 0;
}