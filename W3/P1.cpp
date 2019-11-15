// 3-4 数字三角形问题
#include <bits/stdc++.h>
using namespace std;

// 简版代码(无路径记录)
/*
int main(){
    int n;
    cin>>n;
    int a[n][n], dp[n][n], Max=0;
    for(int i=0;i<n;i++)
        for(int j=0;j<=i;j++)
            cin>>a[i][j];
    
    for(int i=n-1;i>=0;i--){
        for(int j=0;j<=i;j++){
            if(i==n-1)
                dp[i][j] = a[i][j];
            else
                dp[i][j] = max(dp[i+1][j], dp[i+1][j+1]) + a[i][j];
        }
    }
    cout<<dp[0][0]<<endl;
    return 0;
}
*/
int main(){
    int n;
    cin>>n;
    int a[n][n], dp[n][n], Max=0;
    map<pair<int,int>, pair<int,int>> path;
    for(int i=0;i<n;i++)
        for(int j=0;j<=i;j++)
            cin>>a[i][j];
    
    for(int i=n-1;i>=0;i--){
        for(int j=0;j<=i;j++){
            if(i==n-1){
                dp[i][j] = a[i][j];
                path[make_pair(i,j)] = make_pair(-1,-1);
            }else{
                if(dp[i+1][j] > dp[i+1][j+1]){
                    dp[i][j] = dp[i+1][j] + a[i][j];
                    path[make_pair(i,j)] = make_pair(i+1,j);
                }else{
                    dp[i][j] = dp[i+1][j+1] + a[i][j];
                    path[make_pair(i,j)] = make_pair(i+1,j+1);
                }
            }
        }
    }
    cout<<dp[0][0]<<endl;
    // 最大和路径
    cout<<"Path: ";
    int x=0, y=0;
    do{     // 回溯路径
        cout<<a[x][y]<<" ";
        pair<int,int> p = make_pair(x,y);
        x = path[p].first;
        y = path[p].second;
    }while(!(x==-1 && y==-1));
    cout<<endl;
    return 0;
}
/*
5
7
3 8
8 1 0
2 7 4 4
4 5 2 6 5

30
*/

