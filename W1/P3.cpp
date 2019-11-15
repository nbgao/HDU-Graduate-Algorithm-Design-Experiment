#include <bits/stdc++.h>
using namespace std;

/* 先排序后扫描，时间复杂度O(nlogn)
int main(){
    int n;
    cin>>n;
    double a[n];
    for(int i=0;i<n;i++)
        cin>>a[i];
    sort(a,a+n);
    double Max = 0;
    for(int i=1;i<n;i++)
        if(a[i]-a[i-1]>Max)
            Max = a[i] - a[i-1];
    cout<<Max<<endl;
    return 0;
}
*/
    
// 线性时间复杂度O(n)方法
const double INF=1<<30;
int main(){
    int n;
    cin>>n;
    double a[n], Min=INF,Max=-INF,len;
    for(int i=0;i<n;i++){
        cin>>a[i];
        Min = min(Min, a[i]);
        Max = max(Max, a[i]);
    }
    len = (Max-Min)/(n-2);
    double l[n],r[n];   // 区间左右边界位置
    int cnt[n]={0}; //统计每个区间的点数
    fill(l,l+n,INF);
    fill(r,r+n,-INF);

    for(int i=0;i<n;i++){
        int c = (int)((a[i]-Min)/len);
        // if(c>=n-1)
        //     c = n-2;
        cnt[c]++;
        if(a[i]>r[c])
            r[c] = a[i];
        if(a[i]<l[c])
            l[c] = a[i];
    }
    double t=-INF;
    for(int i=1;i<n-1;i++){
        if(cnt[i]==0){
            l[i] = r[i-1];
            r[i] = l[i];
        }
        if(l[i]-r[i-1]>t)
            t = l[i]-r[i-1];
    }
    cout<<t<<endl;

    return 0;
}

/*
5
2.3 3.1 7.5 1.5 6.3

3.2
*/