// Ý tưởng: Sử dụng thuật toán tìm kiếm nhị phân để tìm vị trí của phần tử x trong mảng đã sắp xếp.

#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int x;
    cin >> x;
    int left = 0;
    int right = n - 1;
    int pos = -1;
    int count = 0;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        count++;
        if (a[mid] == x) {
            pos = mid;
            break;   
        } else if (a[mid] < x) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    cout << pos << "\n";
    if (pos != -1) {
        cout << count << "\n";
        }
    return 0;
}