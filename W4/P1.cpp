// 4-1 会场安排问题 [贪心算法]
#include <bits/stdc++.h>
using namespace std;

struct P{
    int a,b;
    int num;
};

bool cmp(P p1, P p2){
    if(p1.a==p2.a)
        p1.b < p2.b;
    return p1.a < p2.a;
}

int main(){
    int n,cnt=1;
    cin>>n;
    P p[n];
    for(int i=0;i<n;i++){
        cin>>p[i].a>>p[i].b;
        p[i].num = 0;
    }
    sort(p,p+n,cmp);
    p[0].num = cnt;
    for(int i=1;i<n;i++){
        bool flag = false;
        for(int j=0;j<i;j++){
            if(p[j].num!=0 && p[j].b<p[i].a){
                p[i].num = p[j].num;
                p[j].num= 0;
                flag = true;
                break;
            }
        }
        if(!flag){
            cnt++;
            p[i].num = cnt;
        }
    }
    cout<<cnt<<endl;
    return 0;
}
/*
5
1 23
12 28
25 35
27 80
36 50

3
*/