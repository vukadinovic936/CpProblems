#include <bits/stdc++.h>
#define vi vector<int>
using namespace std;
int n;
int ar[20];
bool isprime(int N) {
    for(int i=2; i<=sqrt(N); i++) {
        if(N%i==0) return false;
    }
    return true;
}
void backtrack(int prev,vector<int> left,vector<int> result) {
    if((left.empty() || result.size()==n) && isprime(result[0]+result[result.size()-1])) {
        for(int i=0; i<result.size(); i++) {
            if(!(i==result.size()-1)) {
		    cout << result[i] << " ";
            } else {
		   cout << result[i];
	cout << "\n";
            }
        }
    } else {
        for(int i=0; i<left.size(); i++) {
            if(isprime(left[i]+prev)) {
                vi cresult=result;
                vi cleft=left;
                cresult.push_back(cleft[i]);
                cleft.erase(cleft.begin()+i);
                backtrack(cresult[cresult.size()-1],cleft,cresult);
            }
        }
    }
}
int main() {
    int t=0;
    freopen("output.txt","w",stdout);
    while(cin >> n) {
        t++;
        memset(ar,0,sizeof ar);
        vector<int> left;
        vector<int> result;
        for(int i=0; i<n; i++) {
            ar[i]=i+1;
            left.push_back(i+1);
        }
        left.erase(left.begin());
        result.push_back(1);
        cout << "Case " << t <<":"<< "\n";
        backtrack(1,left,result);
	cout << "\n";
    }
}
