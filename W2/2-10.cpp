#include <bits/stdc++.h>
using namespace std;

void MergeAll(int *a, int l, int r){
    
}

void MergeSort(int *a, int l, int r){
    if(l<r){
        int m = int(sqrt(r-l+1));
        if(m>1){
            for(int i=0;i<m;i++)
                MergeSort(a, l+i*m, l+(i+1)*m);
            MergeSort(a, l+m*m, r);
        }
        MergeAll(a, l ,r);
    }
}
/*
T(1) = O(1)                 n<=1
T(n) = sqrt(n)T(sqrt(n))    n>1
T(n) = O(nlogn)
*/
int main(){

    return 0;
}
