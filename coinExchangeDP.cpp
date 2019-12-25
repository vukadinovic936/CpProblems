#include <bits/stdc++.h>
#define vi vector<int>
#define pi pair<int,int>
#define vii vector<pair<int,int>>
using namespace std;
int coins[2];
int memo[1000];
int n;
int rec(int money) {
    if(money==0) return 0;
    if(money<0) return 10000000;
    int res=10000;
    if(memo[money]==-1) {
        for(int i=0; i<n; i++) {
            res=min(1+rec(money-coins[i]),res);
        }
        memo[money]=res;
    }
    return memo[money];
}
int main() {
    n=2;
    int c[2]= {1,5};
    memset(memo,-1,sizeof memo);
    copy(c,c+2,coins);
    int V=10;
    cout << rec(V) << endl;
}
