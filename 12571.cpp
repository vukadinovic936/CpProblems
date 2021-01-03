#include <bits/stdc++.h>
#define vi vector<int>
#define pi pair<int, int>
#define pd pair<double, double>
#define vii vector<pair<int, int>>
#define ll long long
#define INF 1e9
#define EPS 1e-9
using namespace std;
int main() {
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin >> t;
    while(t--){
        int n,q;
        cin >> n >> q;
        int x;
        int m[256] = {};
        while(n--){
            cin >> x;
            m[x&255]=1;
        }
        while(q--){
            int a;
            cin >> a;
            int max_el = 0;

            for(int i=255;i>max_el;i--){
                if(m[i] && (i & a) > max_el)
                    max_el = i&a;
            }
            cout << max_el << endl;
        }
    }
    return 0;
}
