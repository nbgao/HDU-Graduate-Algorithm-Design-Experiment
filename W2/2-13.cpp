#include <bits/stdc++.h>
using namespace std;

// 非增序快速排序
int Partition(int *a, int l, int r){
    int p = a[l];
    while(l<r){
        while(a[r]<p && l<r)
            r--;
        a[l] = a[r];
        while(a[l]>p && l<r)
            l++;
        a[r] = a[l];
    }
    a[l] = p;
    return l;
}

void QuickSort(int *a, int l, int r){
    if(l<r){
        int p = Partition(a, l, r);
        QuickSort(a, l, p-1);
        QuickSort(a, p+1, r);
    }
}

/*
3 5 4 1 8 9 7 2 6 0
*/
int main(){
    int a[10]={3,5,4,1,8,9,7,2,6,0}, n=10;
    QuickSort(a, 0, n-1);
    for(int i=0;i<n;i++){
        if(i==n-1)
            cout<<a[i]<<endl;
        else
            cout<<a[i]<<" ";
    }
    return 0;
}