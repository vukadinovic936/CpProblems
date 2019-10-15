#include <bits/stdc++.h>
#define ll long long
#define INF 10000000
#define vi vector<int>
#define ii pair<int,int>
using namespace std;
class UnionFind {
private:
    vi p,rank;
public:
    UnionFind(int N) {
        rank.assign(N,0);
        p.assign(N,0);
        for(int i=0; i<N; i++) {
            p[i]=i;
        }
    }
    int findSet(int i) {
        return (p[i]==i)? i : (p[i]=findSet(p[i]));
    }
    bool isSameSet(int i, int j) {
        return findSet(i)==findSet(j);
    }
    void unionSet(int i,int j) {
        if(!isSameSet(i,j)) {
            int x=findSet(i);
	    int  y=findSet(j);
            if(rank[x]>rank[y]) {
                p[y]=x;
            }
            else {
                p[x]=y;
                if(rank[x]==rank[y]) rank[y]++;
            }
        }

    };

};
int main() {
    int t;
    cin >> t;
//    freopen("output.txt","w",stdout);
    while(t--) {
        int n;
        cin >> n;
        string str;
        getline(cin,str);
         UnionFind u(n);
        int cnt=0;
        int ncnt=0;
        while(getline(cin,str) && !(str.empty())) {
            stringstream s1(str);
            char command;
            int a;
            int b;
            s1 >> command >> a >> b;
	    a--;
	    b--;
            if(command=='c') {
                u.unionSet(a,b);
            } else {
                if(u.isSameSet(a,b)) cnt++;
                else ncnt++;
            }

        }	
	
	cout << cnt << "," << ncnt << endl;

	if(t!=0){
        cout << endl;
	}
    }
}


