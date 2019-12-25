#include <bits/stdc++.h>
using namespace std;
int M,C;
int gar[30][30];
int memo[220][30];
int rec(int n,int m) {

    if(m<0) {
        return -1000000;
    }
    if(n==C+1) return M-m;
    int mk=-10000;
    if(memo[m][n]==-1) {
        for(int i=1; i<=gar[n][0]; i++) {
            mk=max(rec(n+1,m-gar[n][i]),mk);
        }
        memo[m][n]=mk;
    }
    memo[m][n]=mk;
    memo[m][n]=max(memo[m][n],mk);
    return memo[m][n];
}
int main() {
//freopen("output.txt","w",stdout);
    int N;
    cin >> N;
    while(N--) {
        cin >> M >> C;
        memset(gar,-1,sizeof gar);
        memset(memo,-1,sizeof memo);
        for(int i=1; i<=C; i++) {
            cin >> gar[i][0];
            for(int j=1; j<=gar[i][0]; j++) {
                cin >> gar[i][j];
            }
        }
        int v=rec(1,M);
        if(v>=0) {
            cout << v << endl;
        } else {
            cout << "no solution" << endl;
        }
    }
}


