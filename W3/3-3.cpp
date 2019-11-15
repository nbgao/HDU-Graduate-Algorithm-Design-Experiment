// 完全背包问题
#include <bits/stdc++.h>
using namespace std;

// 空间复杂度O(nb) 时间复杂度O(nb)

int main(){
    int n, b;
    cin>>n>>b;
    int a[n+1], c[n+1], dp[n+1][b+1];
    memset(dp,0,sizeof(dp));
    for(int i=1;i<=n;i++)
        cin>>a[i]>>c[i];
    for(int i=1;i<=n;i++)
        for(int j=0;j<=b;j++){
            if(j<a[i])
                dp[i][j] = dp[i-1][j];
            else
                dp[i][j] = max(dp[i-1][j], dp[i-1][j-a[i]]+c[i]);
        }
    cout<<dp[n][b]<<endl;
    return 0;
}

// 一维滚动数组 空间复杂度O(b) 时间复杂度O(nb)
/*
int main(){
    int n, b;
    cin>>n>>b;
    int a[n], c[n], dp[b+1];
    memset(dp,0,sizeof(dp));
    for(int i=0;i<n;i++)
        cin>>a[i]>>c[i];
    for(int i=0;i<n;i++)
        for(int j=a[i];j<=b;j++)
            dp[j] = max(dp[j], dp[j-a[i]]+c[i]);
    cout<<dp[b]<<endl;
    return 0;
}
*/
/*
4 10
2 1
3 3
4 5
7 9

12
*/