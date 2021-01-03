#include <bits/stdc++.h>
#define vi vector<int>
#define pi pair<int, int>
#define pd pair<double, double>
#define vii vector<pair<int, int>>
#define ll long long
#define INF 1e9
#define EPS 1e-9
using namespace std;
void cntsort(int ar[], int n){
    vector<int> res(n);
    int smallest = INF;
    int biggest = -INF;
    for(int i=0;i<n;i++){
        smallest = min(smallest,ar[i]);
        biggest = max(biggest,ar[i]);
    }
    // create and fill the frequency table
    int k = (biggest-smallest+1);
    vector<int> freq(k);
    for(int i=0;i<n;i++){
        freq[ar[i]-smallest]++;
    }
    // make prefix sums
    for(int i=1;i<k;i++){
        freq[i] += freq[i-1];
    }
    // place elements on their positions
    for(int i=n-1;i>=0;i--){
        res[freq[ar[i]-smallest]-1] = ar[i];
        freq[ar[i]-smallest]--;
    }
    for(int i=0;i<n;i++){
        ar[i] = res[i];
    }
}

void printAr(int ar[], int n){    
  for(int i=0;i<n;i++){    
      if(i!=n-1)
          cout << ar[i] << " ";    
        else
            cout << ar[i] ;
  }    
  cout << endl;    
}
int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    while(cin >> n && n!=0){
        int ar[n];
        for(int i=0;i<n;i++){
            cin >> ar[i];
        }
        cntsort(ar,n);
        printAr(ar,n);
    }
   
}
