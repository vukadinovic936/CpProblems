#include <bits/stdc++.h>
#define vi vector<int>
#define pi pair<int,int>
#define vii vector<pair<int,int>>
#define ll long long int
#define x first
#define y second
using namespace std;
int main() {
    //freopen("output.txt","w",stdout);
    //freopen("input.txt","r",stdin);
    ios ::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int N;
    while(scanf("%d",&N)!=EOF) {
        int ar[N];
        map<int,int> m;
        for(int i=0; i<N; i++) {
            scanf("%d", &ar[i]);
            if(m.count(ar[i])>0){
                m[ar[i]]++;
            }else{
                m[ar[i]]=1;
            }
        }
        int M;
        scanf("%d",&M);
        int I=-1;
        int J=-1;
        for(int i=0; i<N; i++) {
            if((m.count((M-ar[i]))>0 && ar[i]!=(M-ar[i])) || (m[ar[i]]>1 && ar[i]==(M-ar[i]))) {
                if(I==-1 || abs(I-J)>abs(ar[i]-(M-ar[i]))) {
                    if(ar[i]<(M-ar[i])) {
                        I=ar[i];
                        J=(M-ar[i]);
                    } else {
                        I=(M-ar[i]);
                        J=(ar[i]);
                    }

                }
            }
        }

        printf("Peter should buy books whose prices are %d and %d.\n\n",I,J);
    }
}
