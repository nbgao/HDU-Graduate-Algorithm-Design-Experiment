#include <bits/stdc++.h>
using namespace std;

// O(nlogn)
int LIS(int *a, int n){
    // dp[k]表示长度为k序列的最大数
    int dp[n+1];
    fill(dp, dp+n, INT_MAX);
    dp[1] = a[0];
    int k = 1;
    for(int i=1;i<n;i++){
        if(a[i]>dp[k])
            dp[++k] = a[i];
        else
            dp[lower_bound(dp+1, dp+k, a[i])-dp] = a[i];

    }
    return k;
}

int main(){
    int a[10]={3,0,6,1,2,7,4,5,9,8}, n=10;
    cout<<LIS(a, n)<<endl;
}