#include<iostream>
#include<vector>
using namespace std;

struct Diem
{
    int x;
    int y;
};

void Heapify(vector<Diem>&a,int n,int i)
{
    int l = 2*i+1;
    int r = 2*i+2;
    int largest = i;
    if(l < n && ((a[l].x > a[largest].x) || (a[l].x == a[largest].x && a[l].y < a[largest].y)))
        largest = l;
    if(r < n && ((a[r].x > a[largest].x) || (a[r].x == a[largest].x && a[r].y < a[largest].y)))
        largest = r;
    if(i!=largest)
    {
        swap(a[i],a[largest]);
        Heapify(a,n,largest);
    }
}

void HeapSort(vector<Diem>&a,int n)
{
    for(int i = n/2 - 1; i >= 0 ; i--)
        Heapify(a,n,i);
    for(int i = n - 1 ; i >= 0 ; i--)
    {
        swap(a[i],a[0]);
        Heapify(a,i,0);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    vector<Diem>a(n);
    for(int i = 0 ; i < n ; i++)
    {
        cin>>a[i].x>>a[i].y;
    }

    HeapSort(a,n);

    for(int i = 0 ; i < n ; i++)
    {
        cout<<a[i].x<<" "<<a[i].y<<"\n";
    }
    return 0 ;
}