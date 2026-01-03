#include <iostream>
#include <vector>

using namespace std;

void Sort(vector<int> &);

int main()
{
    int n, k;
    vector<int> nums;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> k;
        nums.push_back(k);
    }
    Sort(nums);
    for (int i = 0; i < n; i++) {
        cout << nums[i] << ' ';
    }
    return 0;
}
	
void Insectionsort(vector<int> & Mang) {
    for (int i = 1; i < Mang.size(); i++) {
        int key = Mang[i], j = i - 1;
        while (j >= 0 && Mang[j] > key) {
            Mang[j + 1] = Mang[j];
            j--;
        }
        Mang[j + 1] = key;
    }
}

void Sort(vector<int> & Mang) {
    vector<int> chan;
    vector<int> le;
    for (int i = 0; i < Mang.size(); i++) {
        if (Mang[i] % 2 == 0) {
            chan.push_back(Mang[i]);
        } else {
            le.push_back(Mang[i]);
        }
    }
    Insectionsort(chan);
    Insectionsort(le);
    Mang.clear();
    for (int i = 0; i < chan.size(); i++) {
        Mang.push_back(chan[i]);
    } 
    for (int i = 0; i < le.size(); i++) {
        Mang.push_back(le[i]);
    }
}