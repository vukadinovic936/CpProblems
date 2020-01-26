#include <bits/stdc++.h>
#define vi vector<int>
#define pi pair<int,int>
#define vii vector<pair<int,int>>
#define ll long long int
using namespace std;
int main() {
    int ar[5]={7,6,6,5,10};
    int output[5];
    int count[100];
    memset(count,0,sizeof count);
    memset(output,0,sizeof output);
    for(int i=0;i<5;i++){
        count[ar[i]]++;
    }
    for(int i=1;i<100;i++){
        count[i]+=count[i-1];
    }
    for(int i=0;i<5;i++){
        output[count[ar[i]]-1]=ar[i];
        count[ar[i]]--;
    }
    for(int i=0;i<5;i++){
        cout << output[i]  << "  ";
    }
}

