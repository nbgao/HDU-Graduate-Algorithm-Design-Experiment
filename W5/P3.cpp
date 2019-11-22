// 5-13 工作分配问题 [回溯法]
#include <bits/stdc++.h>
#define N 21
using namespace std;

int n,m,d;
int c[N][N];

void F(int &Min, int *x, int *r, int i){
    if(i>n){
        int s=0;
        for(int j=1;j<=n;j++)
            s += c[j][x[j]];
        if(s < Min){
            Min = s;
            for(int j=1;j<=n;j++)
                r[j] = x[j];
        }
        return ;
    }
    for(int j=i;j<=n;j++){
        swap(x[i], x[j]);
        F(Min, x, r, i+1);
        swap(x[i], x[j]);
    }
    return ;
}

// x[i]表示工作i分配的人员号,r表示最佳分配列表，Min表示最小总费用
int main(){
    cin>>n;
    int x[n], r[n], Min=INT_MAX;
    for(int i=1;i<=n;i++)   //初始化配对
        x[i] = i;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            cin>>c[i][j];

    F(Min, x, r, 1);
    cout<<Min<<endl;
    // for(int i=1;i<=n;i++)
    //     cout<<r[i]<<" ";
    return 0;
}
/*
3
10 2 3
2 3 4
3 4 5

9
*/