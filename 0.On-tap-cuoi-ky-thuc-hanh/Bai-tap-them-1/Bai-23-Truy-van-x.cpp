// Ý tưởng: Sắp xếp mảng ban đầu và sử dụng tìm kiếm nhị phân để kiểm tra sự tồn tại của phần tử x trong mảng.

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, q;
    cin >> n >> q;
    vector<long long> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    while (q--) { // Xử lý từng truy vấn
        long long x; 
        cin >> x;
        if (binary_search(a.begin(), a.end(), x)) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
    return 0;
}