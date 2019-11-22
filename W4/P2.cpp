// 4-6 最优服务次序 [贪心算法]
#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    int a[n];
    double sum = 0;
    for(int i=0;i<n;i++)
        cin>>a[i];
    sort(a,a+n);
    for(int i=0;i<n;i++)
        sum += (n-i)*a[i];
    printf("%.2f\n", sum/n);
    return 0;
}
/*
10
56 12 1 99 1000 234 33 55 99 812

532.00
*/