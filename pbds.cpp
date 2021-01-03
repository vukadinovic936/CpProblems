#include <bits/stdc++.h>
#define vi vector<int>
#define pi pair<int, int>
#define pd pair<double, double>
#define vii vector<pair<int, int>>
#define ll long long
#define INF 1e9
#define EPS 1e-9
using namespace std;
// POLICY BASED DATA STRUCTURE
#include <bits/extc++.h> 
using namespace __gnu_pbds;
typedef tree<int, null_type, less<int>, rb_tree_tag,
             tree_order_statistics_node_update> ost;
int main() {
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n = 9;
    int A[] = {2, 4, 7, 10, 15, 23, 50, 65, 71};
    ost tree;
    for(int i=0; i<n;i++){
        tree.insert(A[i]);
    }
    // O(log n) select
    cout << *tree.find_by_order(0) << endl;
    cout << *tree.find_by_order(n-1) << endl;
    cout << *tree.find_by_order(4) << endl;
    // O(log n) rank
    cout << tree.order_of_key(2) << endl;
    cout << tree.order_of_key(71) << endl;
    cout << tree.order_of_key(15) << endl;
    return 0;
}
