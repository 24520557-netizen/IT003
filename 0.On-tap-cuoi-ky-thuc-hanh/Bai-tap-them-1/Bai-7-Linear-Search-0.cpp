#include <iostream>
using namespace std;
int search(int arr[], int N, int x){
    for (int i = 0; i < N; i++) {
        if (arr[i] == x) {
            return i;
        }
    }
    return -1;
}

int main(){
    int arr[100],n , x;
    cin >> n;
    for (int i = 0; i < n ; i++)    
        cin>>arr[i];
    cin>>x;
    cout<<search(arr, n, x)<<endl;
    return 0;
}