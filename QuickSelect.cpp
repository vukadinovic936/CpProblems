#include <bits/stdc++.h>
using namespace std;

int RandPartition(int A[], int l, int r){
    // here pivot should be random
    int pivot = A[r];
    int i = (l - 1);
  
    for (int j = l; j <= r - 1; j++)  
    {  
        if (A[j] < pivot)  
        {  
            i++; 
            swap(A[i], A[j]);  
        }  
    }  
    swap(A[i + 1], A[r]);  
    return (i + 1);  
}
int QuickSelect(int A[], int l, int r, int k){
    if(l==r)
        return A[l];
    int q = RandPartition(A, l, r);
    if(q+1 == k)
        return A[q];
    else if (q+1 >k)
        return QuickSelect(A, l, q-1, k);
    else 
        return QuickSelect(A, q+1, r, k);
}
// N-TH element default function
