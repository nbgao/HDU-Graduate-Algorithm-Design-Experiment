// 6-5 运动员最佳配对问题 [分支限界法(优先级队列)]
#include <bits/stdc++.h>
#define N 21
using namespace std;

int n;
int P[N][N], Q[N][N];

struct S{
    int id, sum, Max;
    int *x;
};

int Compute(int k, int *x){
    int s = 0;
    for(int i=1;i<=k;i++)
        s += P[i][x[i]]*Q[x[i]][i];
    return s;
}

struct cmp{
    bool operator()(S a, S b){
        return a.Max < b.Max;
    }
};

int BFS(){
    int Max = 0;
    priority_queue<S, vector<S>, cmp> q;
    S s = S{1,0,0};
    s.x = new int[n+1];
    for(int i=1;i<=n;i++)
        s.x[i] = i;
    
    q.push(s);
    while(!q.empty()){
        S p = q.top();
        q.pop();
        if(p.id == n){
            int t = Compute(n, p.x);
            if(t>Max)
                Max = t;
            return Max;
        }
        for(int i=p.id+1;i<=n;i++){
            S r;
            r.x = new int[n+1];
            r.id = p.id + 1;
            r.Max = p.Max;
            for(int j=1;j<=n;j++)
                r.x[j] = p.x[j];
            int u = r.id;
            r.x[u] = p.x[i];
            r.x[i] = p.x[u];
            r.Max = Compute(r.id , r.x);
            q.push(r);
        }
    }
}

// x[i]表示第i个男运动员与配对的女运动员号,r表示最佳配对列表，Max表示最佳竞赛优势总和
int main(){
    cin>>n;
    int x[n], Max=0;
    for(int i=1;i<=n;i++)   //初始化配对
        x[i] = i;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            cin>>P[i][j];
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            cin>>Q[i][j];
    
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