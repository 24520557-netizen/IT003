#include <iostream>

#define MAX 10000

using namespace std;

struct Hocsinh{
    string Hodem, Ten;
    bool Gioitinh;
    int Ngay, Thang, Nam;
    double Toan, Van, Ly, Hoa, Anh, Sinh;
};

void InputElement(Hocsinh &x) {
    getline(cin>>ws, x.Hodem);
    getline(cin>>ws, x.Ten);
    cin >> x.Gioitinh;
    cin >> x.Ngay >> x.Thang >> x.Nam;
    cin >> x.Toan >> x.Van >> x.Ly >> x.Hoa >> x.Anh >> x.Sinh;
}

int BSearch(Hocsinh [], int, Hocsinh);

int main()
{
    Hocsinh ds[MAX], hs;
    int n;

    cin >> n;
    for (int i = 0; i < n; i++) {
        InputElement(hs);
        ds[i] = hs;
    }
    InputElement(hs);
    cout << BSearch(ds, n, hs) << endl;
    return 0;
}

int Compare(Hocsinh Hs1, Hocsinh Hs2) {
    if (Hs1.Ten == Hs2.Ten) {
        if (Hs1.Hodem == Hs2.Hodem) {
            if (Hs1.Nam == Hs2.Nam) {
                if (Hs1.Thang == Hs2.Thang) {
                    if (Hs1.Ngay == Hs2.Ngay) {
                        return 0;
                    } else if (Hs1.Ngay > Hs2.Ngay) {
                        return -1;
                    } else {
                        return 1;
                    }
                } else if (Hs1.Thang > Hs2.Thang) {
                    return -1;
                } else {
                    return 1;
                }
            } else if (Hs1.Nam > Hs2.Nam) {
                return -1;
            } else {
                return 1;
            }
        } else if (Hs1.Hodem < Hs2.Hodem) {
            return -1;
        } else {
            return 1;
        }
    } else if (Hs1.Ten < Hs2.Ten) {
        return -1;
    } else {
        return 1;
    }
    return 0;
}

int BSearch(Hocsinh Ds[MAX], int size, Hocsinh Hs) {
    int left = 0, right = size - 1, middle, step = 0;
    while (left <= right) {
        middle = (left + right) / 2;
        step++;
        if (Compare(Hs, Ds[middle]) == -1) {
            right = middle - 1;
        } else if (Compare(Hs, Ds[middle]) == 1) {
            left = middle + 1;
        } else {
            return step;
        }
    }
    return 0;
}
