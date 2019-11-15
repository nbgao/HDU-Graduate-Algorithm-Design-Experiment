// 0-1二维费用背包
#include <bits/stdc++.h>
using namespace std;

// 0-1一维背包问题 空间复杂度O(nc) 时间复杂度O(nc)
/*
int main(){
    int n,c;
    cin>>n>>c;
    int w[n+1], v[n+1];
    for(int i=1;i<=n;i++)
        cin>>w[i]>>v[i];
    int dp[c+1];
    memset(dp,0,sizeof(dp));
    for(int i=1;i<=n;i++)
        for(int j=c;j>=w[i];j--)
            dp[j] = max(dp[j], dp[j-w[i]]+v[i]);
    cout<<dp[c]<<endl;
    return 0;
}
*/
// 0-1一维背包问题 空间复杂度O(c) 时间复杂度O(nc)
/*
int main(){
    int n,c;
    cin>>n>>c;
    int w[n], v[n];
    for(int i=0;i<n;i++)
        cin>>w[i]>>v[i];
    int dp[c+1];
    memset(dp,0,sizeof(dp));
    for(int i=0;i<n;i++)
        for(int j=c;j>=w[i];j--)
            dp[j] = max(dp[j], dp[j-w[i]]+v[i]);
    cout<<dp[c]<<endl;
    return 0;
}
*/
/*
3 6
3 5
2 4
4 2

9
*/


// 0-1二维背包问题 空间复杂度O(ncd) 时间复杂度O(ncd)
/*
int main(){
    int n,c,d;
    cin>>n>>c>>d;
    int w[n+1], b[n+1], v[n+1], dp[n+1][c+1][d+1];
    memset(dp,0,sizeof(dp));
    for(int i=1;i<=n;i++) 
        cin>>w[i]>>b[i]>>v[i];
    for(int i=1;i<=n;i++)
        for(int j=c;j>=0;j--)
            for(int k=d;k>=0;k--){
                if(j<w[i] || k<b[i])
                    dp[i][j][k] = dp[i-1][j][k];
                else
                    dp[i][j][k] = max(dp[i-1][j][k], dp[i-1][j-w[i]][k-b[i]]+v[i]);
            }
    cout<<dp[n][c][d]<<endl;

    return 0;
}
*/
// 0-1二维背包问题 空间复杂度O(cd) 时间复杂度O(ncd)

int main(){
    int n,c,d;
    cin>>n>>c>>d;
    int w[n], b[n], v[n], dp[c+1][d+1];
    memset(dp,0,sizeof(dp));
    for(int i=0;i<n;i++)
        cin>>w[i]>>b[i]>>v[i];
    for(int i=0;i<n;i++){
        for(int j=c;j>=w[i];j--)
            for(int k=d;k>=b[i];k--)
                dp[j][k] = max(dp[j][k], dp[j-w[i]][k-b[i]]+v[i]);
    }
    cout<<dp[c][d]<<endl;
    return 0;
}

/*
5 8 7
3 2 6
4 1 5
6 4 7
1 1 3
2 4 8

17
*/