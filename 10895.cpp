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
    int m,n;
    while(cin >> m >> n){
        vector<pi> v[m];
        int r;
        int temp;

        for(int i=0;i<m;i++){
            cin >> r; 
            for(int j=0;j<r;j++){
                cin >> temp;
                v[i].push_back(make_pair(temp,0));
            }
            for(int j=0;j<r;j++){
                cin >> temp;
                v[i][j].second = temp;
            }
        }

        vector<pi> v2[n];
        for(int i=0;i<m;i++){
            for(auto j : v[i]){
                v2[j.first-1].push_back(make_pair(i+1,j.second));
            }
        }
        cout << n << " " << m << endl;
        for(int i=0;i<n;i++){
            cout << v2[i].size();
            for(auto j:v2[i]){
                cout << " " << j.first;
            }
            cout << endl;
            for(auto j:v2[i]){
                if(j != *v2[i].begin())
                    cout << " " << j.second;
                else
                    cout <<  j.second;
            }
            cout << endl;
        }
    }
    return 0;
}
