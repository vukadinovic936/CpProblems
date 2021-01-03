#include <bits/stdc++.h>
#define vi vector<int>
#define pi pair<int,int>
#define vii vector<pair<int,int>>
#define ll long long int
#define x first
#define y second
using namespace std;
int main() {
//    freopen("output.txt","w",stdout);
//    freopen("input.txt","r",stdin);
    ios ::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    int ar[n][n];
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cin >> ar[i][j];
            if(i>0) ar[i][j]+=ar[i-1][j];
            if(j>0) ar[i][j]+=ar[i][j-1];
            if(i>0 && j>0) ar[i][j]-=ar[i-1][j-1];
        }
    }
    int max_el=0;
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            for(int k=i; k<n; k++) {
                for(int m=j; m<n; m++) {
                    int res=0;
                    res+=ar[k][m];
                    if(j>0)
                        res-=ar[k][j-1];
                    if(i>0)
                        res-=ar[i-1][m];
                    if(j>0 && i>0)
                        res+=ar[i-1][j-1];

                    max_el=max(res,max_el);
                }
            }
        }
    }
    cout << max_el << endl;
}
