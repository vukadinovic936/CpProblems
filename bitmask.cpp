#include <bits/stdc++.h>
#define vi vector<int>
using namespace std;
int main() {
    int t;
    cin >> t;
    while(t--) {
        int l;
        int b;
	cin >> l >> b;
        int ar[b];
        for(int i=0; i<b; i++) {
            cin >> ar[i];
        }
        int bitmask=0;
	bool done=false;
        for(int bitmask=0;bitmask<(1<<b);bitmask++) {
            int sum=0;
            for(int i=0; i<b; i++) {
                if(1<<i & bitmask)
                    sum+=ar[i];
            }
	    if(sum==l) {
		    cout << "YES" << endl;
		    done=true;
		    break;
	    }
        }
	if(!done) cout << "NO" << endl;
    }
}

