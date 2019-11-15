// 3-6 租用游艇问题
#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    int a[n][n], dp[n];
    for(int i=0;i<n;i++)
        for(int j=i+1;j<n;j++)
            cin>>a[i][j];
    // dp[j]表示到ｊ的最小费用
    fill(dp,dp+n,INT_MAX);
    dp[1] = a[0][1];
    for(int j=2;j<n;j++)
        for(int i=1;i<j;i++)
            dp[j] = min(dp[j], dp[i]+a[i][j]);  
    cout<<dp[n-1]<<endl;
    return 0;
}
/*
3
5 15
7

12
*/