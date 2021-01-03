#include <bits/stdc++.h>
#define vi vector<int> #define pi pair<int,int>
#define vii vector<pair<int,int>>
#define ll long long int
#define EPS 1e-9
using namespace std;

struct point {
    double x,y;
    bool operator==(point a) const {
        if(a.x==x && a.y== y)return true;
        else return false;
    }
};
double dist(point p1, point p2) {
// Euclidean distance
// hypot(dx, dy) returns sqrt(dx * dx + dy * dy)
    return hypot(p1.x - p2.x, p1.y - p2.y);
}
struct vec {
    double x, y; // name: ‘vec’ is different from STL vector
    vec(double _x, double _y) : x(_x), y(_y) {}
};
vec toVec(point a, point b) {
// convert 2 points to vector a->b
    return vec(b.x - a.x, b.y - a.y);
}
double cross(vec a, vec b) {
    return a.x * b.y - a.y * b.x;
}
bool ccw(point p, point q, point r) {
    return cross(toVec(p, q), toVec(p, r)) > 0;
}
bool collinear(point p, point q, point r) {
    return fabs(cross(toVec(p, q), toVec(p, r))) < EPS;
}
int sign(double x) {
    if(x>0) return 1;
    if(x<0) return -1;
    return 0;
}
point pivot;
bool angleCmp(point a, point b) {
    if (collinear(pivot, a, b))
        return dist(pivot, a) < dist(pivot, b);
    double d1x = a.x - pivot.x, d1y = a.y - pivot.y;
    double d2x = b.x - pivot.x, d2y = b.y - pivot.y;
    return (atan2(d1y, d1x) - atan2(d2y, d2x)) < 0;
}
vector<point> CH(vector<point> P) {
// the content of P may be reshuffled
    int i, j, n = (int)P.size();
    if (n <= 3) {
        if (!(P[0] == P[n-1])) P.push_back(P[0]); // safeguard from corner case
        return P;
    }
}
int main() {
    //freopen("output.txt","w",stdout);
//    freopen("input.txt","r",stdin);
    ios ::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    vector<point> P(n);
    for(int i=0; i<n; i++) {
        cin >> P[i].x;
        cin >> P[i].y;
    }
    int P0 = 0;
    for (int i = 1; i < n; i++)
        if (P[i].y < P[P0].y || (P[i].y == P[P0].y && P[i].x > P[P0].x))
            P0 = i;
    point temp = P[0];
    P[0] = P[P0];
    P[P0] = temp;
    pivot = P[0];
    sort(++P.begin(), P.end(), angleCmp);
    // continuation from the earlier part
// third, the ccw tests
    vector<point> S;
    S.push_back(P[n-1]);
    S.push_back(P[0]);
    S.push_back(P[1]);
// initial S
    int i = 2;
// then, we check the rest
    while (i < n) {
// note: N must be >= 3 for this method to work
        int j = (int)S.size()-1;
        if (ccw(S[j-1], S[j], P[i])) S.push_back(P[i++]); // left turn, accept
        else S.pop_back();
    }
// or pop the top of S until we have a left turn

    double result = 0.0, x1, y1, x2, y2;
    for (int i = 0; i < (int)S.size()-1; i++) {
        x1 = S[i].x;
        x2 = S[i+1].x;
        y1 = S[i].y;
        y2 = S[i+1].y;
        result += (x1 * y2 - x2 * y1);
    }
    printf("%.1f", fabs(result) /2.0);
}
