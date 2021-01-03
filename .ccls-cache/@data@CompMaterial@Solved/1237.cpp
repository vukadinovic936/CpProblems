#include <bits/stdc++.h>
#define vi vector<int>
#define pi pair<int,int>
#define vii vector<pair<int,int>>
#define ll long long int
#define x first
#define y second
using namespace std;
int main() {
    // freopen("output.txt","w",stdout);
  //  freopen("input.txt","r",stdin);
    ios ::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin >> t;
    while(t--) {
        int D;
        cin >> D;
        vector<pair<string,pair<int,int>>> v;
        for(int i=0; i<D; i++) {
            string M;
            int L;
            int H;
            cin >> M;
            cin >> L >> H;
            v.push_back({M,{L,H}});
        }
        int Q;
        cin >> Q;
        for(int i=0; i<Q; i++) {
            int P;
            cin >> P;
            string res="nan";
            for(auto j:v) {
                if(j.y.x<=P && j.y.y>=P) {
                    if(res=="nan") {
                        res=j.x;
                    } else if(res!="nan") {
                        res="nan";
                        break;
                    }
                }
            }
            if(res=="nan") {
                cout << "UNDETERMINED" << endl;
            } else {
                cout << res << endl;
            }

        }
        if(t!=0)
        cout << "\n";
    }
}
