#include <bits/stdc++.h>
#define vi vector<int>
#define pi pair<int,int>
#define vii vector<pair<int,int>>
#define ll long long int
#define x first
#define y second
using namespace std;
void clear( std::queue<pi> &q )
{
    std::queue<pi> empty;
    std::swap( q, empty );
}
int main() {
   // freopen("output.txt","w",stdout);
    //freopen("input.txt","r",stdin);
    ios ::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin >> t;
    while(t--) {
        int n,m;
        cin >> n >> m;
        n+=2;
        m+=2;
        int ar[n][m];
        vii fire;
        pi joe;

        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(i==0 || j==0 || j==(m-1) || i==(n-1)) {
                    ar[i][j]=3;
                } else {
                    char c;
                    cin >> c;
                    if(c=='#') {
                        ar[i][j]=0;
                    } else if(c=='J') {
                        ar[i][j]=1;
                        joe= {i,j};
                    } else if(c=='.' || c==',') {
                        ar[i][j]=2;
                    } else if(c=='F') {
                        ar[i][j]=-1;
                        fire.push_back({i,j});
                    }

                }
            }
        }
        queue<pi> fireq;
        for(auto i:fire) {
            fireq.push(i);
        }
        queue<pi> joeq;
        joeq.push(joe);
        queue<pi> newj ;
        queue<pi> newf;
        bool stop=false;
        int steps=0;
 /*for(int i=0;i<n;i++){
                   for(int j=0; j<m; j++) {
                        cout << ar[i][j] << " ";
                    }
                    cout << endl;
                }
                cout << "NEWW \n\n ";
            
*/
        while((!joeq.empty() || !fireq.empty()) && stop==false) {
            steps++;
            while(!joeq.empty()) {
                pi cur=joeq.front();
                joeq.pop();
                if(ar[cur.x][cur.y]!=1) continue;

                if(ar[cur.x+1][cur.y]==2) {
                    ar[cur.x+1][cur.y]=1;
                    newj.push({cur.x+1,cur.y});
                }
                if(ar[cur.x-1][cur.y]==2)
                {
                    ar[cur.x-1][cur.y]=1;
                    newj.push({cur.x-1,cur.y});
                }
                if(ar[cur.x][cur.y+1]==2)
                {
                    ar[cur.x][cur.y+1]=1;
                    newj.push({cur.x,cur.y+1});
                }
                if(ar[cur.x][cur.y-1]==2)
                {
                    ar[cur.x][cur.y-1]=1;
                    newj.push({cur.x,cur.y-1});
                }

                if(ar[cur.x+1][cur.y]==3) {
                    cout<< steps << endl;
                    stop=true;
                    break;
                }
                if(ar[cur.x-1][cur.y]==3)
                {

                    cout<< steps << endl;
                    stop=true;
                    break;
                }
                if(ar[cur.x][cur.y+1]==3)
                {

                    cout<< steps << endl;
                    stop=true;
                    break;
                }
                if(ar[cur.x][cur.y-1]==3)
                {

                    cout<< steps << endl;
                    stop=true;
                    break;
                }

            }
            while(!fireq.empty() && !stop) {
                pi cur=fireq.front();
                fireq.pop();
                if(ar[cur.x+1][cur.y]==2 || ar[cur.x+1][cur.y]==1) {
                    ar[cur.x+1][cur.y]=-1;
                    newf.push({cur.x+1,cur.y});
                }
                if(ar[cur.x-1][cur.y]==2 || ar[cur.x-1][cur.y]==1)
                {
                    ar[cur.x-1][cur.y]=-1;
                    newf.push({cur.x-1,cur.y});
                }
                if(ar[cur.x][cur.y+1]==2 || ar[cur.x][cur.y+1]==1)
                {
                    ar[cur.x][cur.y+1]=-1;
                    newf.push({cur.x,cur.y+1});
                }
                if(ar[cur.x][cur.y-1]==2 || ar[cur.x][cur.y-1]==1)
                {
                    ar[cur.x][cur.y-1]=-1;
                    newf.push({cur.x,cur.y-1});
                }

                /*for(int i=0;i<n;i++){
                   for(int j=0; j<m; j++) {
                        cout << ar[i][j] << " ";
                    }
                    cout << endl;
                }
                cout << "NEWW \n\n ";
                */
            }
            fireq=newf;
            joeq=newj;
            clear(newf);
            clear(newj);
            if(joeq.empty() && !stop) {
                cout << "IMPOSSIBLE\n";
                break;
            }
        }
    }
}
