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
void copyAr(int ar1[], int ar2[], int from, int to){
    // ar1 = ar2[from], ar2[from+1] ... ar2[to-1], ar2[to]
    int j = 0;
    for(int i=from;i<=to;i++){
        ar1[j] = ar2[i];
        j++;
    }
}
void mergeSort(int ar[],int begin, int end){
    /* Implementation of Merge sort 
       Input arguments are
       ar - array to be sorted
       begin - first index of the element to be sorted
       end - last index of the array to be sorted
       EX: mergeSort(ar,0,9) for array of length 10
    */

    // we call the fcn recursively until we split them in 1 element arrays
    if(begin < end){
        int mid = begin+ (end-begin+1)/2;
        mergeSort(ar,begin,mid-1);
        mergeSort(ar,mid,end);

        int i = 0;
        int j = 0;

        int l1 = mid-begin;
        int l2 = end-mid+1;
        
        int ar1[l1];
        int ar2[l2];

        // probably other way for copying arrays exists but I defined my own fcn
        copyAr(ar1, ar, begin, mid-1);
        copyAr(ar2, ar, mid, end);

        int k = begin; 
        while(i < l1 && j < l2){
            if(ar1[i]<ar2[j]){
                ar[k] = ar1[i];
                i++;
            }else{
                ar[k] = ar2[j];
                j++;
            }
            k++;
        }

        while(i < l1){
            ar[k] = ar1[i];
            k++;
            i++;
        }
        while(j<l2){
            ar[k] = ar2[j];
            k++;
            j++;
        }
    }

}
int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int ar[10] = { 5, 4, 2, 1, 8, 9, 7, 3, 6, 10};

    mergeSort(ar,0,9);
    printAr(ar,10);
    
}
