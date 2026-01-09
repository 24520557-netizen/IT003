#include <iostream>
#include <vector>

using namespace std;

void solve(int n) {
    vector <int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int x;
    cin >> x;
    vector <int> diachi; // vector lưu chỉ số các vị trí của x trong mảng a
    for (int i = 0; i < n; i++) {
        if (a[i] == x) {
            diachi.push_back(i);
        }
    }
    cout << diachi.size() << endl;
    for (int i = 0; i < diachi.size(); i++) {
        int index = diachi[i];
        int solanduyet = index + 1;
        cout << index << " " << solanduyet << endl;
    }
}

int main() {
    int n;
    cin >> n;
    solve(n);
    return 0;
}