#include <bits/stdc++.h>
#define vi vector<int>
#define pi pair<int,int>
#define vii vector<pair<int,int>>
#define ll long long int
#define x first
#define y second
using namespace std;
int main() {
//    freopen("output.txt","w",stdout);
//    freopen("input.txt","r",stdin);
    ios ::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin >> t;
    int cas=0;
    while(t--){
        cas++;
        int n;
        cin >> n;
        char ar[n];
        for(int i=0;i<n;i++){
            cin >> ar[i];
        }
        int cnt=0;
        for(int i=0;i<n;i++){
            if(ar[i]=='.'){
                cnt++;
                if(i+2<n && ar[i+2]=='.'){
                    i=i+2;  
                }else{
                    i=i+1;
                }
            }
        }
        printf("Case %d: %d\n",cas,cnt);
    }
}
