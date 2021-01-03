#include <bits/stdc++.h>
#define vi vector<int>
#define vll vector<long long>
#define pi pair<int, int>
#define pd pair<double, double>
#define vii vector<pair<int, int>>
#define ll long long
#define INF 1e9
#define EPS 1e-9
#define LSOne(S) ((S) & -(S))
using namespace std;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin >> t;
    while(t--){

        set<pi> s;
        int n,m;
        cin >> n >> m;
        int ar[n][m];
        bool no=false;
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                cin >> ar[i][j];

        for(int j=0;j<m;j++){
            vector<int> temp;
            for(int i=0;i<n;i++){
                if(ar[i][j] == 1)
                    temp.push_back(i);
            }
            if(temp.size()!=2)
                no=true;
            else{
                s.insert(make_pair(temp[0],temp[1]));
            }
        }
        if(no || s.size()!=m){
            cout << "No" << endl;
        }else{
            cout << "Yes" << endl;
        }
    }
    return 0;
}
