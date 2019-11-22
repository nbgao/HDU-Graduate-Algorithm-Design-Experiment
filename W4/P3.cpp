// 4-9 汽车加油问题 [贪心算法]
#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,k,cnt=0;
    cin>>n>>k;
    int a[k+1];
    for(int i=0;i<=k;i++)
        cin>>a[i];
    for(int i=0,s=0;i<=k;i++){
        if(a[i]>n){
            cnt = -1;
            break;
        }
        s += a[i];
        if(s>n){
            cnt++;
            s = a[i];
        }
    }

    cout<<cnt<<endl;
    return 0;
}
/*
7 7
1 2 3 4 5 1 6 6

4
*/