#include <bits/stdc++.h>
#define ll long long
#define INF 10000000
#define vi vector<int>
#define ii pair<int,int>
using namespace std;
class UnionFind {
private:
    vi p;
    vi r;
public:
    UnionFind(int n) {
        p.assign(n,0);
        r.assign(n,0);
        for(int i=0; i<n; i++) {
            p[i]=i;
        }
    }
    int findSet(int i) {
        return (p[i]==i) ? i : (p[i]=findSet(p[i]));
    }
    bool isSameSet(int i,int j) {
        return findSet(i) == findSet(j);
    }
    int returnRank(int i) {
        return r[i];
    }
    bool UnionSet(int i,int j) {
        if(!isSameSet(i,j)) {
            int x=findSet(i), y=findSet(j);
            if( r[x] >= r[y] ) {
                p[y]=x;

                if(r[x]==r[y]) r[y]++;
            }
            else
                p[x]=y;

            return true;
        } else {
            return false;
        }
    }

};
int main() {

    int n;
    int m;
    while(cin >> n>> m){
    map<char,int> cells;
    char a,b,c;
    cin >> a >> b >> c ;
    UnionFind *u= new UnionFind(n);
    cells.insert(make_pair(a,0));
    cells.insert(make_pair(b,1));
    cells.insert(make_pair(c,2));
    u->UnionSet(cells[a],cells[b]);
    u->UnionSet(cells[a],cells[c]);
    int counter=3;
    char connect[m][2];
    for(int i=0; i<m; i++) {
        cin >> connect[i][0] >> connect[i][1];
        if(cells.find(connect[i][0])==cells.end()) {
            cells.insert(make_pair(connect[i][0],counter));
            counter++;
        }
        if(cells.find(connect[i][1])==cells.end()) {
            cells.insert(make_pair(connect[i][1],counter));
            counter++;
        }
    }
    bool changed=true;
    int years=0;

    while(changed) {
        years++;
        changed=false;
        int nums[n]= {0};
        for(int i=0; i<m; i++) {
            int a=cells[connect[i][0]];
            int b=cells[connect[i][1]];

            if(u->findSet(a)==0) {
                nums[cells[connect[i][1]]]++;
            }

            if(u->findSet(b)==0) {
                nums[cells[connect[i][0]]]++;
            }
        }

        for(int i=1; i<n; i++) {
            if(nums[i]>=3) {
                if( u->UnionSet(0,i) ) changed=true;
            }
        }
    }
    bool notgood=false;
    for(int i=0; i<n; i++) {
        if(u->findSet(i)!=0) {
            notgood=true;
        }
    }
    if(notgood) {
        cout << "THIS BRAIN NEVER WAKES UP" << endl;
    } else {
        if(n==3) {
            cout << "WAKE UP IN, " <<  0 << ", YEARS" << endl; } else {
            years--;
            cout << "WAKE UP IN, " <<  years << ", YEARS" << endl;
        }
    }

    }

}
