#include <bits/stdc++.h>
#define vi vector<int>
#define pi pair<int,int>
#define vii vector<pair<int,int>>
#define ll long long int
#define x first
#define y second
using namespace std;
bool isprime(int n) {
    for(int i=2; i<=sqrt(n); i++) {
        if(n%i==0) {
            return false;
        }
    }
    return true;
}
void rec(int start,vector<int> used,vector<int> unused) {
    if(unused.empty() && isprime(used[used.size()-1]+1)) {
        for(int i=0;i<used.size();i++) {
            cout << used[i];
            if(i!=(used.size()-1))
                cout << " ";
        }
        cout << endl;
    }
    for(int i=0; i<unused.size(); i++) {
        int cur=unused[i];
        if(isprime(start+cur)) {
            vector<int> t1=used;
            vector<int> t2=unused;
            t1.push_back(cur);
            t2.erase(t2.begin()+i);
            rec(cur,t1,t2);
        }
    }
}
int main() {
    //freopen("output.txt","w",stdout);
     //freopen("input.txt","r",stdin);
   // ios ::sync_with_stdio(false);
   // cin.tie(nullptr);
   // cout.tie(nullptr);
    int n;
    int cnt=0;
    while(cin >> n) {
        cnt++;
        cout << "Case " <<cnt << ":\n";
        vector<int> us;
        us.push_back(1);
        vector<int> anus;
        for(int i=2; i<=n; i++) {
            anus.push_back(i);
        }
        rec(1,us,anus);
         cout << "\n";
    }
}
