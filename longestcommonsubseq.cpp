#include <bits/stdc++.h>
#define vi vector<int>
#define pi pair<int,int>
#define vii vector<pair<int,int>>
#define ll long long int
using namespace std;

int lookup[21][21];
int LCSLength(string X,string Y,int m,int n) {
    if(m==0 || n==0)
        return 0;
    if(lookup[m][n]==0) {
        if(X[m-1] == Y[n-1])
            return lookup[m][n]=  LCSLength(X,Y,m-1,n-1)+1;
        else
            lookup[m][n]=max(LCSLength(X,Y,m,n-1),LCSLength(X,Y,m-1,n));
    }
    return lookup[m][n];
}
int main() {
    //freopen("output.txt","w",stdout);
    freopen("input.txt","r",stdin);

    ios ::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    string X = "ABCBDAB", Y = "BDCABA";

    // create a map to store solutions of subproblems
    unordered_map<string, int> lookup;

    cout << "The length of LCS is "
         << LCSLength(X, Y, X.length(), Y.length());

}
