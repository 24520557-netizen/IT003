// Ý tưởng: Sắp xếp mảng để dễ dàng tìm các phần tử lớn nhất và nhỏ nhất.
// Tính hai tùy chọn:
// 1. Hiệu của tổng hai phần tử lớn nhất và tổng hai phần tử nhỏ nhất.
// 2. Hiệu giữa phần tử lớn nhất và phần tử nhỏ nhất.
// Kết quả là giá trị lớn hơn trong hai tùy chọn trên.

#include <iostream>
#include <vector>
#include <climits>
using namespace std;

void quicksort(vector<long long>& a, int left, int right) {
    int i = left, j = right;
    long long tmp;
    long long pivot = a[(left + right) / 2];

    while (i <= j) {
        while (a[i] < pivot)
            i++;
        while (a[j] > pivot)
            j--;
        if (i <= j) {
            tmp = a[i];
            a[i] = a[j];
            a[j] = tmp;
            i++;
            j--;
        }
    }

    if (left < j)
        quicksort(a, left, j);
    if (i < right)
        quicksort(a, i, right);
}

void solve() {
    int n;
    cin >> n;
    vector <long long> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    quicksort(a, 0, n - 1);
    long long option1 = 0;
    if (n >= 2) {
         option1 = (a[n-1] + a[n-2])  - (a[0] + a[1]);
    }  
    long long option2 = a[n-1] - a[0];
    cout << max(option1, option2) << endl;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}
