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
//    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    UnionFind UF(5);
    printf("%d\n", UF.numDisjointSets());

    UF.unionSet(0,1);
    printf("%d\n", UF.numDisjointSets());

    UF.unionSet(2,3);
    printf("%d\n", UF.numDisjointSets());

    UF.unionSet(4,3);
    printf("%d\n", UF.numDisjointSets());
    printf("isSameSet(0,3) = %d\n", UF.isSameSet(0,3));
    printf("isSameSet(4,3) = %d\n", UF.isSameSet(4,3));
    for (int i = 0; i<5;i++)
        printf("findSet(%d) = %d, sizeofSet(%d) = %d\n", i, UF.findSet(i), i, UF.sizeOfSet(i));
    UF.unionSet(0,3);
    printf("%d\n", UF.numDisjointSets());
    for(int i=0;i<5;i++){
        printf("findSet(%d) = %d, sizeOfSet(%d) = %d\n", i, UF.findSet(i), i, UF.sizeOfSet(i));
    }
    return 0;
}
