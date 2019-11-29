// 6-5 运动员最佳配对问题 [分支限界法(优先级队列)]
#include <bits/stdc++.h>
#define N 21
using namespace std;

int n;
int P[N][N], Q[N][N], maxout[N];

struct S{
    int id;
    int sum;
    int Max;
    int up;
    int *x;
};

struct cmp{
    bool operator()(S a, S b){
        return a.up < b.up;
    }
};

int BFS(){
    priority_queue<S, vector<S>, cmp> q;
    S s = S{1,0,0,0};
    for(int i=1;i<=n;i++)
        s.Max += maxout[i];
    s.up = s.Max;
    s.x = new int[n+1];
    for(int i=1;i<=n;i++)
        s.x[i] = i;

    q.push(s);
    while(!q.empty()){
        S p = q.top();
        q.pop();
        if(p.id > n)
            return p.sum;
            
        for(int i=p.id;i<=n;i++){
            S r;
            r.id = p.id+1;
            r.x = new int[n+1];
            for(int j=1;j<=n;j++)
                r.x[j] = p.x[j];
            int u = p.id;
            r.x[u] = p.x[i];
            r.x[i] = p.x[u];
            r.sum = p.sum + P[u][r.x[u]]*Q[r.x[u]][u];
            r.Max = p.Max - maxout[u];
            r.up = r.sum + r.Max;
            q.push(r);
        }
    }
}

// x[i]表示第i个男运动员与配对的女运动员号,r表示最佳配对列表，Max表示最佳竞赛优势总和
int main(){
    cin>>n;
    int x[n], r[n], Max=0;
    for(int i=1;i<=n;i++)   //初始化配对
        x[i] = i;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            cin>>P[i][j];
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            cin>>Q[i][j];
    
    for(int i=1;i<=n;i++){
        int t = 0;
        for(int j=1;j<=n;j++)
            t = max(t, P[i][j]*Q[j][i]);
        maxout[i] = t;
    }
    cout<<BFS()<<endl;

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