#include <bits/stdc++.h>
using namespace std;

void BinaraySearch(int *a, int n, double x, int &i, int &j){
    int l=0, r=n-1, m;
    while(l<=r){
        m = (l+r)/2;
        if(a[m]==x){
            i = j = m;
            return;
        }
        if(a[m]<x)
            l = m + 1;
        else
            r = m - 1;
        i = r;
        j = l;
    }
    //return;
}

int main(){
    int n=10;
    int a[n]={0,1,2,3,4,5,6,7,8,9}, l=0, r=n-1;
    int i=0, j=n-1;
    double x;
    cin>>x;
    if(x<a[l])  // 超出左边界
        cout<<-1<<" "<<0<<endl;
    else if(x>a[r])     // 超出右边界
        cout<<n<<" "<<-1<<endl;
    else{
        BinaraySearch(a, n, x, i, j);
        cout<<i<<" "<<j<<endl;
    }
    return 0;
}