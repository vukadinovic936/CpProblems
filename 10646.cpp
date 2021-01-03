#include <bits/stdc++.h>
#define vi vector<int>
#define pi pair<int, int>
#define pd pair<double, double>
#define vii vector<pair<int, int>>
#define ll long long
#define INF 1e9
#define EPS 1e-9
using namespace std;

int convert(string s){
    int res;
    res = (s[0]-'0');
    if(res<2 || res>9){
        res = 10;
    }
    return res;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin >> t;
    int cnt=0;
    while(t--){
        cnt++;
        string cards[52];
        for(int i=0;i<52;i++){
            cin >> cards[i];
        }
        int value = 0;
        int sub = 0;

        for(int i=0;i<3;i++){
            value += convert(cards[26-sub]); 
            sub = sub + (10-convert(cards[26-sub]))+1;
        }
        if(value < (26-sub)){
            cout << "Case " << cnt << ": " << cards[value-1] << endl;
        }else{
            cout << "Case " << cnt << ": " << cards[sub+value-1] << endl;
        }

    }
}
