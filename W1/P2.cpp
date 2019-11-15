#include<bits/stdc++.h>
using namespace std;

int C(int n, int m){
    int s = 1;
    for(int i=n;i>n-m;i--)
        s *= i;
    for(int i=1;i<=m;i++)
        s /= i;
    return s;
}

// 以i号字母开头，长度为k的字符串数量
int F(int i, int k){    
    int s=0;
    if(k==1)
        return 1;
    for(int j=i+1;j<=26;j++)
        s += F(j, k-1);
    return s;
}

// 长度为k的字符串数量
int G(int k){
    int s=0;
    for(int i=1;i<=26;i++)
        s += F(i, k);
    return s;
}

int main(){
    string s;
    cin>>s;
    int l = s.length(), sum=0;
    for(int i=1;i<l;i++)
        sum += G(i);
    for(int i=0,b=0;i<l;i++){   // b为前一字符号
        int x = s[i]-'a'+1;
        int k = l-i;
        for(int j=b+1;j<x;j++)
            sum += F(j, k);
        b = x;
    }
    cout<<sum<<endl;
    return 0;
}