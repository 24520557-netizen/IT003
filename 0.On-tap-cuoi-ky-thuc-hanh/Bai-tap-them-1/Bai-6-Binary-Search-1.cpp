// Ý tưởng: Sử dụng thuật toán tìm kiếm nhị phân để tìm vị trí của phần tử x trong mảng đã sắp xếp.

#include <iostream>
#include <vector>

using namespace std;

int BinarySearch(const vector<int>& a, int x, int& count) {
    int left = 0;
    int right = a.size() - 1;
    count = 0;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        count++;
        if (a[mid] == x) {
            return mid;   
        } else if (a[mid] < x) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return -1;
}
int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int x;
    cin >> x;
    int count;
    int pos = BinarySearch(a, x, count);
    cout << pos << "\n";
    if (pos != -1) {
        cout << count << "\n";
    }
}