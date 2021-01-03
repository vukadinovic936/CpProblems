#include <bits/stdc++.h>
#define vi vector<int>
#define pi pair<int, int>
#define pd pair<double, double>
#define vii vector<pair<int, int>>
#define ll long long
#define INF 1e9
#define EPS 1e-9
using namespace std;
class UnionFind {
    private:
        vi p, rank, setSize;
        int numSets;
    public:
        UnionFind(int N){
            // create N nodes
            // set parent of each to itself
            p.assign(N,0);
            for(int i=0;i<N;++i)
                p[i]=i;
            // set rank of each to 0
            rank.assign(N,0);
            setSize.assign(N,1);
            numSets = N; 
        }
        int findSet(int i){
            if(p[i] == i)
                return i;
            else
                return (p[i] = findSet(p[i]));
        }
        bool isSameSet(int i, int j){
            return findSet(i) == findSet(j);
        }
        void unionSet(int i, int j){
            if (isSameSet(i,j)) return;
            int x = findSet(i);
            int y = findSet(j);
            if(rank[x] > rank[y])
                swap(x,y);
            p[x] = y;
            if(rank[x] == rank[y])
                ++rank[y];

            setSize[y] += setSize[x];
            --numSets;
        }
        int numDisjointSets(){
            return numSets;
        }
        int sizeOfSet(int i){
            return setSize[findSet(i)];
        }

};
int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n,m;
    // 0 is infected
    while(cin >> n >> m && n!=0){
        UnionFind UF(n);
        int k;
        for(int i=0;i<m;i++){
            cin >> k;
            int ar[k];
            int smallest= INF;
            for(int j=0;j<k;j++){
                cin >> ar[j];
                smallest = min(smallest,ar[j]);
            }
            for(int j=0;j<k;j++){
                UF.unionSet(ar[j],smallest);
            }
        }
        cout << UF.sizeOfSet(0) << endl;
    }

    return 0;
}
