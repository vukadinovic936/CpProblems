#include <bits/stdc++.h>
#define vi vector<int>
#define pi pair<int,int>
#define vii vector<pair<int,int>>
using namespace std;
bool d[8];
bool b[8];
queue<int> q;
vector<int> ar[8];
void dfs(int u) {
    d[u]=true;
    printf("%d ", u);
    for(int i=0; i<(int) ar[u].size(); i++) {
        if(d[ar[u][i]]==false)
            dfs(ar[u][i]);
    }
}
void bfs(int u) {
    q.push(u);
    while(!q.empty()) {
        int u = q.front();
        b[u]=true;
        printf("%d ",u);
        q.pop();
        for(int i=0;i<(int) ar[u].size();i++){
            if(b[ar[u][i]]==false){
                q.push(ar[u][i]);
                b[ar[u][i]]=true;
            }
        }
    }
}
int main() {
    memset(d,false,sizeof d);
    memset(b,false,sizeof b);
    ar[1]= {2,4,5};
    ar[2]= {1,7,6,3};
    ar[3]= {2};
    ar[4]= {1};
    ar[5]= {1};
    ar[6]= {2};
    ar[7]= {2};
    dfs(1);
    printf("\n");
    bfs(1);

}
