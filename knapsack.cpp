#include <bits/stdc++.h>
#define vi vector<int>
#define pi pair<int,int>
#define vii vector<pair<int,int>>
using namespace std;
int n;
int V[4];
int W[4];
int memo[1000][1000];
int rec(int id,int remW) {

    if(remW==0) return 0;

    if(id==n) return 0;

    if(W[id]>remW) {

        if(memo[id+1][remW]==-1)
        memo[id+1][remW] = rec(id+1,remW);  
        return memo[id+1][remW];

    }

    if(W[id]<=remW) {

        if(memo[id+1][remW-W[id]]==-1){
            memo[id+1][remW-W[id]]=rec(id+1,remW-W[id]); 
        }

        if(memo[id+1][remW]==-1){
            memo[id+1][remW]=rec(id+1,remW);
        }

        return max(V[id]+memo[id+1][remW-W[id]],memo[id+1][remW]);
    }
}
int main() {
    n=4;
    int v[4]= {100,70,50,10};
    int w[4]= {10,4,6,12};
    memset(memo,-1, sizeof memo);
    copy(v,v+4,V);
    copy(w,w+4,W);
    cout << rec(0,12) << endl;
}
