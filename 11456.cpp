#include <bits/stdc++.h>
#define vi vector<int>
#define pi pair<int,int>
#define vii vector<pair<int,int>>
#define ll long long int
using namespace std;
int main() {
    //  freopen("output.txt","w",stdout);
    //freopen("input.txt","r",stdin);
    ios ::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<int> cars(n);
        vector<int> lis(n);
        vector<int> lds(n);
        for(int i=0; i<n; i++) {
            cin >> cars[i];
            lis[i]=1;
            lds[i]=1;
        }
        reverse(cars.begin(),cars.end());
        for(int i=1;i<n;i++){
            for(int j=i-1;j>=0;j--){
               if(cars[i]>cars[j] && lis[j]>=lis[i]){
                   lis[i]=lis[j]+1;
               }
            }
        }
       for(int i=1;i<n;i++){
            for(int j=i-1;j>=0;j--){
               if(cars[i]<cars[j] && lds[j]>=lds[i]){
                   lds[i]=lds[j]+1;
               }
            }
        }
       int maks=-1;
       for(int i=0;i<n;i++){
            maks=max(maks,(lis[i]+lds[i]-1));
       }
       cout << maks << endl;
    }
}

