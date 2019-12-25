#include <bits/stdc++.h>
using namespace std;
/* TEST CASES YOU CAN TRY
 *
 * 5
 * 3 10 2 1 20
 * RESULT : length:3  numbers: 3 10 20
 *
 * 2
 * 3 2  
 *
 * 6
 *
 * 50 3 10 7 40 80
 * 3 7 40 80
 * Result 4. numbers 3 7 40 80
 */
int main() {
    int n;
    cin >> n;
    int ar[n];
    pair<int,vector<int>> res[n];
    for(int i=0; i<n; i++) {
        cin >> ar[i];
	vector<int> p;
	p.push_back(ar[i]);
	res[i]={1,p};
    }
    for(int i=1; i<n; i++) {
        for(int j=(i-1); j>=0; j--) {
		if(ar[i]>ar[j]){
			if(res[j].first+1> res[i].first){
				res[i].first=res[j].first+1;
				res[i].second=res[j].second;
				res[i].second.push_back(ar[i]);
			}
		}
        }
    }
    int maks=0;
    for(int i=0;i<n;i++)
	    maks=max(maks,res[i].first);

    for(int i=0;i<n;i++){
	    if(maks==res[i].first){
		    cout <<"Max subsequence length: " <<  maks << endl;
		    cout << "Max subsequence numbers: " << endl;
		    for(auto i: res[i].second)
			    cout << i << endl;

		   break;
	    }
    }
}
