// 5-4 运动员最佳配对问题 [回溯法]
#include <bits/stdc++.h>
#define N 21
using namespace std;

int n,m,d;
int p[N][N], q[N][N];

void F(int &Max, int *x, int *r, int i){
    if(i>n){
        int s=0;
        for(int j=1;j<=n;j++)
            s += p[j][x[j]] * q[x[j]][j];
        if(s > Max){
            Max = s;
            for(int j=1;j<=n;j++)
                r[j] = x[j];
        }
        return ;
    }
    for(int j=i;j<=n;j++){
        swap(x[i], x[j]);
        F(Max, x, r, i+1);
        swap(x[i], x[j]);
    }
    return ;
}

// x[i]表示第i个男运动员与配对的女运动员号,r表示最佳配对列表，Max表示最佳竞赛优势总和
int main(){
    cin>>n;
    int x[n], r[n], Max=0;
    for(int i=1;i<=n;i++)   //初始化配对
        x[i] = i;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            cin>>p[i][j];
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            cin>>q[i][j];
    
    F(Max, x, r, 1);
    cout<<Max<<endl;
    return 0;
}
/*
3
10 2 3
2 3 4
3 4 5
2 2 2
3 5 3
4 5 1

52
*/