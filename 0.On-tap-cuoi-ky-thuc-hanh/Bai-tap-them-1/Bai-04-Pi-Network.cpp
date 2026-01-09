// Ý tưởng: Sử dụng thuật toán TÌM KIẾM NHỊ PHÂN để tìm min_gia: n_(ban <= min_gia) >= n_(gia_mua >= min_gia) 

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int upper_bound(const vector<int>& arr, int value) {
    int left = 0, right = arr.size();
    while (left < right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] <= value) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }
    return left;
}

int lower_bound(const vector<int>& arr, int value) {
    int left = 0, right = arr.size();
    while (left < right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] < value) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }
    return left;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> nguoiban(n);
    for (int i = 0; i < n; i++) {
        cin >> nguoiban[i];
    }
    vector<int> nguoimua(m);
    for (int i = 0; i < m; i++) {
        cin >> nguoimua[i];
        }
    sort(nguoiban.begin(), nguoiban.end());
    sort(nguoimua.begin(), nguoimua.end());
    long long thap = 0, cao = 1000000007;
    long long result = -1;
    while (thap <= cao) {
        long long mid = thap + (cao - thap) / 2;
        int so_nguoi_ban = upper_bound(nguoiban, mid);
        int so_nguoi_mua = m - lower_bound(nguoimua, mid);
        if (so_nguoi_ban >= so_nguoi_mua) {
            result = mid;
            cao = mid - 1;
        } else {
            thap = mid + 1;
        }
    }
    cout << result << endl;
    return 0;
}
