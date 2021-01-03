#include <bits/stdc++.h>
#define vi vector<int>
#define pi pair<int, int>
#define pd pair<double, double>
#define vii vector<pair<int, int>>
#define ll long long
#define INF 1e9
#define EPS 1e-9
using namespace std;

void printAr(int ar[], int n){
    for(int i=0;i<n;i++){
        cout << ar[i] << " ";
    }
    cout << endl;
}
void quickSort(int ar[],int begin, int end){

    /* Implementation of quickSort algorithm
     * arguments:
     * ar - array to be sorted
     * begin - index of the first element in the array
     * end - index of the last element in the array
     * we always pick a pivot to be last el of the array
     * then we proceed as theory tells us 
     * i is pointer from the left
     * j is end-1 becuase end is pivot
    */
    if(begin >= (end))
        return;

    int p = ar[end];
    int i = begin;
    int j = end-1;

    while(i<=j){

        if(ar[i] > p && ar[j] < p){

            swap(ar[i],ar[j]);
        }else{

        if(ar[i] < p)
            i++;        

        if(ar[j] > p)
            j--;
        } 
    }

    swap(ar[i],ar[end]);

    quickSort(ar,0,i-1);
    quickSort(ar,i+1, end);
}
int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int ar[10] = { 5, 4, 2, 1, 8, 9, 7, 3, 6, 10};

    quickSort(ar,0,9);

    printAr(ar,10);
    
}
