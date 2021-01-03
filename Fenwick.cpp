#include <bits/stdc++.h>
#define vi vector<int>
#define pi pair<int, int>
#define pd pair<double, double>
#define vii vector<pair<int, int>>
#define ll long long
#define INF 1e9
#define EPS 1e-9
#define LSOne(S) ((S) & -(S))
using namespace std;
class FenwickTree {
    private:
        vi ft;
    public:
        FenwickTree(int m){
            ft.assign(m+1, 0);
        }
        int rsq(int j){
            int sum = 0;
            for(; j; j-=LSOne(j))
                sum+=ft[j];
            return sum;
        }
        int rsq(int i, int j){
            return rsq(j) - rsq(i-1);
        }
        void update(int i, int v){
            for(; i < (int)ft.size(); i+=LSOne(i)){
                ft[i] += v;
            }
        }
};
int main() {
//    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}
