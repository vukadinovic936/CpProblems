#include <bits/stdc++.h>
#define vi vector<int>
#define pi pair<int,int>
#define vii vector<pair<int,int>>
using namespace std;
int l;
int n;
int memo[60][60];
vector<int> A;
int cut(int left, int right) {
    if (left + 1 == right)       return 0;
    if(memo[left][right]!=-1) return memo[left][right];
    int ans = 2000000000;

    for (int i = left + 1; i < right; i++) {
        ans = min(ans, cut(left, i) + cut(i, right) + (A[right]-A[left]));
    }

    return memo[left][right]=ans;
}
int main() {
    // l<1000
    while(cin >> l && l!=0) {
        // n<50
        cin >> n;
        A.clear();
        A.push_back(0);
        memset(memo,-1,sizeof memo);
        for(int i=0; i<n; i++) {
            int temp;
            cin >> temp;
            A.push_back(temp);
        }
        A.push_back(l);
        printf("The minimum cutting is %d.\n", cut(0,n+1));
    }
}
