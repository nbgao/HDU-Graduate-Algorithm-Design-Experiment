// 5-3 最小重量机器设计问题 [回溯法]
#include <bits/stdc++.h>
#define N 1001
#define M 1001
using namespace std;

int n,m,d;
int w[N][M], c[N][M];

bool F(int &min_w, int *x, int *r, int sum_w, int sum_c, int i){
    if(i>n){
        min_w = sum_w;
        for(int j=1;j<=n;j++)
            r[j] = x[j];
        return true;
    }
    bool found = false;
    if(min_w<=d)
        found = true;
    for(int j=1;j<=m;j++){
        x[i] = j;
        sum_w += w[i][j];
        sum_c += c[i][j];
        if(sum_c <= d && sum_w<min_w)
            if(F(min_w, x, r, sum_w, sum_c, i+1))
                found = true;
        sum_w -= w[i][j];
        sum_c -= c[i][j];
    }
    return found;
}

int main(){
    cin>>n>>m>>d;
    int x[n], r[n], min_w=INT_MAX;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            cin>>c[i][j];
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            cin>>w[i][j];
    
    F(min_w, x, r, 0, 0, 1);
    cout<<min_w<<endl;
    for(int i=1;i<=n;i++){
        if(i==n)
            cout<<r[i]<<endl;
        else
            cout<<r[i]<<" ";
    }
    return 0;
}
/*
3 3 4
1 2 3
3 2 1
2 2 2
1 2 3
3 2 1
2 2 2

4
1 3 1
*/