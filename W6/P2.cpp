// 6-10 世界名画陈列问题 [分支限界法(优先级队列)]
#include <bits/stdc++.h>
using namespace std;

int m,n,cnt;
const int N = 31;
int x[N][N];

struct P{
    int x[N][N];
    int t,s;
    P(int _x[N][N], int _t, int _s){
        for(int i=1;i<N;i++)
            for(int j=1;j<N;j++)
                x[i][j] = _x[i][j];
        t = _t;
        s = _s;
    };
    friend bool operator < (P a, P b){
        return a.s > b.s;
    }
};

int Solve(){
    int Min = INT_MAX;
    priority_queue<P> q;
    for(int i=0;i<(1<<n);i++){  // 所有可行初始结点入堆
        int sum = 0;
        int v[N][N];
        memset(v,0,sizeof(v));
        for(int j=1;j<=n;j++){
            if(i & (1<<(j-1))){
                if(v[i][j] == 0)  // 置为机器人
                    v[1][j] = 1;
                if(v[1][j-1] == 0)    // 左侧被监视覆盖
                    v[1][j-1] = 2;
                if(v[1][j+1] == 0)    // 右侧被监视覆盖
                    v[1][j+1] = 2;
                if(v[2][j] == 0)    // 下侧被监视覆盖
                    v[2][j] = 2;
                sum++;  // 机器人数增加
            }
        }
        q.push(P{v, 1, sum});   // 入队列
    }
    while(!q.empty()){
        P p = q.top();
        q.pop();
        int t = p.t;
        if(p.s >= Min)  // 当前活节点的机器人数未低于最小值 (剪枝操作)
            continue;
        if(t == m+1){   // 到达叶子结点判断合法性
            bool flag = true;
            for(int i=1;i<=m && flag;i++)
                for(int j=1;j<=n && flag;j++)
                    if(p.x[i][j]==0)
                        flag = false;
            if(!flag)    // 判断是否全部监视到
                continue;

            if(Min > p.s){  //   最佳解替换
                Min = p.s;
                for(int i=1;i<=m;i++)
                    for(int j=1;j<=n;j++)
                        x[i][j] = p.x[i][j];
                for(int i=1;i<=n;i++){
                    if(x[m+1][i]==1){
                        x[m][i] = 1;
                        Min++;
                    }
                }
            }
        }

        int sum = 0;
        int r[N][N];
        memset(r, 0, sizeof(r));
        for(int i=0;i<=m;i++)
            for(int j=0;j<=n;j++)
                r[i][j] = p.x[i][j];
        for(int i=1;i<=n;i++){
            if(r[t][i] == 0){
                if(r[t][i] != 1)
                    r[t][i] = 2;
                if(r[t+1][i+1] != 1)
                    r[t+1][i+1] = 2;
                if(r[t+1][i-1] != 1)
                    r[t+1][i-1] = 2;
                if(r[t+1][i] != 1)
                    r[t+1][i] = 1;
                if(r[t+2][i] != 1)
                    r[t+2][i] = 2;
                sum++;
            }
        }
        q.push(P{r, t+1, p.s+sum});
    }
    return Min;
}

// x[i]表示
int main(){
    cin>>m>>n;
    memset(x, 0, sizeof(x));
    int cnt = Solve();
    cout<<cnt<<endl;
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++)
            cout<<(x[i][j]==1?1:0)<<" ";  
        cout<<endl;
    }
    return 0;
}
/*
4 4
4
0 0 1 0 
1 0 0 0 
0 0 0 1 
0 1 0 0 


2 5
3
0 0 1 0 0 
1 0 0 0 1 
*/