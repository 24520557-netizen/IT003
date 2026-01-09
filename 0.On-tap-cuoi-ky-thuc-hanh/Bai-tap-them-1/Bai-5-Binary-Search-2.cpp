// Ý tưởng: Sử dụng thuật toán tìm kiếm nhị phân để tìm một chuỗi trong mảng các chuỗi đã được sắp xếp.
// Đếm số lần so sánh được thực hiện trong quá trình tìm kiếm.

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector <string> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    string x;
    cin >> x;
    int left = 0;
    int right = n - 1;
    int Ketqua = -1;
    int dem = 0;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        dem++;
        if (a[mid] == x) {
            Ketqua = mid;
            break;
        } else if (a[mid] < x) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    cout << Ketqua << "\n";
    if (Ketqua != -1) {
        cout << dem << "\n"; 
    }
    return 0;
}