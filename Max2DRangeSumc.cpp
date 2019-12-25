#include <bits/stdc++.h>
using namespace std;
int main() {
    int n=4;
    int ar[4][4]= {
        {0,-2,-7,0},
        {9,2,-6,2},
        {-4,1,-4,1},
        {-1,8,0,-2}
    };
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            if(i>0)
                ar[i][j]+=ar[i-1][j];
            if(j>0)
                ar[i][j]+=ar[i][j-1];
            if(i>0 && j>0)
                ar[i][j]-=ar[i-1][j-1];
        }
    }
    /* for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout << ar[i][j] <<  " ";
        }
        cout << endl;
    } */
    int sum=0;
    for(int i=0; i<n; i++)for(int j=0; j<n; j++)
            for(int x=i; x<n; x++)for(int y=j; y<n; y++) {
                    int sub=ar[x][y];
                    if(i>0)
                        sub-=ar[i-1][y];
                    if(j>0)
                        sub-=ar[x][j-1];
                    if(i>0 && j>0)
                        sub+=ar[i-1][j-1];
                    sum=max(sub,sum);
                    sub=0;
                }
    cout << sum << endl;
}
