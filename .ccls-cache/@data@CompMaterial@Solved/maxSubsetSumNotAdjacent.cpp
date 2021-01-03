int maxSubsetSum(vector<int> arr) {
  int n=arr.size();
int incl = arr[0]; 
int excl = 0; 
int excl_new;
 for(int i=1;i<n;i++){

     excl_new=max(incl,excl);

     incl=excl+arr[i];
     excl=excl_new;
 }
 return max(incl,excl);
}
