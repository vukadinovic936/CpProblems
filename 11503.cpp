#include <bits/stdc++.h>
#define ll long long #define INF 10000000
#define vi vector<int>
#define ii pair<int,int>
#define MOD 1000000007
using namespace std;
class UnionFind {
private:
    vi rank;
    vi p;
public:
    UnionFind(int n) {
        rank.assign(n,1);
        p.assign(n,0);
        for(int i=0; i<n; i++) {
            p[i]=i;
        }
    }
    void unionSet(int i,int j) {
        if(isSameSet(i,j)==false) {
            int x=findSet(i);
            int y=findSet(j);
            if(rank[x]>rank[y]) {
                p[y]=x;
		rank[x]+=rank[y];
            } else {
                p[x]=y;
		rank[y]+=rank[x];
            }
        }
    }
    int findSet(int i) {
        return( p[i]==i ? p[i] : p[i]=findSet(p[i]));
    }
    bool isSameSet(int i,int j) {
        return (findSet(i)==findSet(j));
    }
    int sizeOfSet(int i){
	    return rank[findSet(i)];
    }
};
int main() {
    int t;
    cin >> t;
    freopen("output.txt","w",stdout);

        map<string,int> people;
    while(t--) {
	people.clear();	
        int parents[100000];
        for(int i=0; i<100000; i++) parents[i]=1;
        int cnt=0;
        int n;
        cin >> n;
        UnionFind *u= new UnionFind(100000);
        string s1;
        string s2;
        int i1;
        int i2;
        for(int i=0; i<n; i++) {
            cin >> s1 >> s2;
            if(people.find(s1)==people.end()) {
                people[s1]=cnt;
                cnt++;
            }
            i1=people[s1];

            if(people.find(s2)==people.end()) {
                people[s2]=cnt;
                cnt++;
            }
            i2=people[s2];

            u->unionSet(i1,i2);
	    int res= u->sizeOfSet(i2);
            cout << res << endl;

        }
    }
}

