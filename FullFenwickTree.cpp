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
class FenwickTree{
    private:
        vll ft;
    public:
        FenwickTree(int m){
            ft.assign(m+1,0);
        }
        
        void build(const vll &f){
            int m = (int) f.size()-1;
            ft.assign(m+1,0);
            for(int i = 1; i <=m; i++){
                ft[i] += f[i];
                if (i+LSOne(i) <=m)
                    ft[i+LSOne(i)] += ft[i];
            }
        }

        FenwickTree(const vll &f){
            build(f);
        }

        FenwickTree(int m, const vi &s){
            vll f(m+1, 0);
            for(int i=0;i< (int) s.size();++i){
                ++f[s[i]];
                build(f);
            }
        }

        ll rsq(int j){
            ll sum = 0;
            for(; j; j-=LSOne(j))
                sum += ft[j];
            return sum;
        }
        ll rsq(int i, int j){
            return rsq(j) - rsq(i-1);
        }
        
        void update(int i, ll v){
            for(; i<(int) ft.size();i+=LSOne(i))
                ft[i] +=v;
        }
        
        int select(ll k){
            int lo = 1, hi = ft.size()-1;
            for (int i=0; i<30; i++){
                int mid = (lo+hi) /2;
                (rsq(1,mid) < k) ? lo = mid : hi = mid;
            }
            return hi;
        }

};
class RUPQ{
    private:
        FenwickTree ft;
    public:
        RUPQ(int m) : ft(FenwickTree(m)) {}
    void range_update(int ui, int uj, int v){
        ft.update(ui, v);
        ft.update(uj+1, -v);
    }
    ll point_query(int i){
        return ft.rsq(i);
    }
};
class RURQ {
    private:
        RUPQ rupq;
        FenwickTree purq;
    public:
        RURQ(int m) : rupq(RUPQ(m)), purq(FenwickTree(m)) {}

        void range_update(int ui, int uj, int v){
            rupq.range_update(ui, uj, v);
            purq.update(ui, v*(ui-1));
            purq.update(uj+1, -v*uj);
        }
        ll rsq(int j){
            return rupq.point_query(j)*j - purq.rsq(j);
        }
        ll rsq(int i, int j){
            return rsq(j) - rsq(i-1);
        }
};
int main() {
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    vll f = {0, 0, 1, 0, 1, 2, 3, 2, 1, 1, 0};
    FenwickTree ft(f);
    printf("%lld\n", ft.rsq(1, 6));
    printf("%d\n", ft.select(7));
    ft.update(5, 1);
    printf("%lld\n", ft.rsq(1, 10));
    printf("=====\n");
    RUPQ rupq(10);
    RURQ rurq(10);

    rupq.range_update(2, 9, 7);
    rurq.range_update(2, 9, 7);
    rupq.range_update(6, 7, 3);
    rurq.range_update(6, 7, 3);

    for (int i = 1; i <= 10; i++)
        printf("%d -> %lld\n",i, rupq.point_query(i));
    printf("RSQ(1,10) = %lld\n", rurq.rsq(1,10));
    printf("RSQ(6,7) = %lld\n", rurq.rsq(6,7));

    return 0;
}
