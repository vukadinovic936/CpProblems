#include <bits/stdc++.h>
#define vi vector<int>
using namespace std;
int ar[100];
int n;
int t;
set<string> s;
void backtrack(int c,int sum,vector<int> v) {
    sum=sum+ar[c];
    v.push_back(ar[c]);
    if(sum==t) {
	string tem="";
	for(int i=0;i<v.size();i++){	
		tem=tem+to_string(v[i]);
		if(i!=v.size()-1) tem+="+";
	}
	s.insert(tem);
    } else if(sum<t) {
        for(int i=c+1; i<n; i++) {
            backtrack(i,sum,v);
        }
    }
}
int main() {

    while(cin >> t >> n && t!=0) {
	s.clear();

        memset(ar,0,sizeof ar);
        for(int i=0; i<n; i++) {
            cin >> ar[i];
        }

        for(int i=0; i<n; i++) {
            vector<int> v;
            backtrack(i,0,v);
        }
	printf("Sums of %d:\n",t);
	if(s.empty()) printf("%s\n","NONE");
	for(auto i=s.rbegin();i!=s.rend();++i){
		cout << *i << endl;
	}
    }
}
