#include <bits/stdc++.h>
using namespace std;

int cnt[10];

int W(int n){
    return int(log10(n))+1;
}

int getFirst(int n){
    return n/int(pow(10, W(n)-1));
}

int getRes(int n){
    return n%int(pow(10, W(n)-1));
}

int getZero(int n){
    if(n==1)
        return 1;
    return getZero(n-1) + int(pow(10,n-1));
}

void Solve(int n){
    int t = getFirst(n);
    int r = getRes(n);
    int w = W(n);
    for(int i=0;i<10;i++)
        cnt[i] += t*(w-1)*int(pow(10,w-2));
    for(int i=0;i<t;i++)
        cnt[i] += int(pow(10, w-1));
    cnt[t] += r+1;
    if(r==0){
        cnt[0] += w-1;
        return;
    }
    int l = log10(r)+1;
    if(l!=w-1)
        cnt[0] += (w-1)*(r+1);
    Solve(r);
}

int main(){
    memset(cnt, 0, sizeof(cnt));
    int n;
    cin>>n;
    Solve(n);
    cnt[0] -= getZero(W(n));
    for(int i=0;i<10;i++)
        cout<<i<<": "<<cnt[i]<<endl;
    return 0;
}