#include <bits/stdc++.h>
using namespace std;

// O(n^2)
int LIS(int *a, int n){
    // dp[k]表示以a[k]为最后数的最大递增长度
    int dp[n], Max=1;
    for(int i=0;i<n;i++){
        dp[i] = 1;
        for(int j=0;j<i;j++){
            if(a[j]<a[i])
                dp[i] = max(dp[i], dp[j]+1);
        }
        Max = max(Max, dp[i]);
    }
    return Max;
}

int main(){
    int a[10]={3,0,6,1,2,7,4,5,9,8}, n=10;
    cout<<LIS(a, n)<<endl;
}