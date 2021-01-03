#include <bits/stdc++.h>
#define vi vector<int>
#define pi pair<int, int>
#define pd pair<double, double>
#define vii vector<pair<int, int>>
#define ll long long
#define INF 1e9
#define EPS 1e-9
using namespace std;
int result;
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
            else{
                int j = findSet(p[i]);
                result += abs(i-p[i])%1000;
                return j;
            }
        }

        void unionSet(int i, int j){
            if (i==j) return;

            p[i] = j;

            setSize[i] += setSize[j];
            --numSets;
        }
        int numDisjointSets(){
            return numSets;
        }
        int sizeOfSet(int i){
            return setSize[findSet(i)];
        }

};
int main(){
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        UnionFind UF(n+1);
        string s;
        while(cin >> s && s!="O"){
            int a,b;
            if(s == "I"){
                cin >> a;
                cin >> b;
                UF.unionSet(a,b);
            }else if(s == "E"){
                cin >> a;
                result = 0;
                UF.findSet(a);
                cout << result << endl;
            }
        }
    }
    return 0;
}
