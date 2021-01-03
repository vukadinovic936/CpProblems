#include <bits/stdc++.h>
#define vi vector<int>
#define pi pair<int,int>
#define vii vector<pair<int,int>>
using namespace std;
int main() {
    vector<int>v;
    int n;
    cin >> n;
    int temp;
    for(int i=0; i<n; i++) {
        cin >> temp;
        v.push_back(temp);
    }
    vector<int> l;
    l.push_back(v[0]);
    int mak=0;
    for(int i=1; i<v.size(); i++) {

        int temp=upper_bound(l.begin(),l.end(),v[i])-l.begin();

        if(temp<l.size() && v[i]!=l[temp-1] && v[i]!=l[temp+1]) {

            l[temp]=v[i];

        } else if(temp==l.size()) {

            if(v[i]!=l[l.size()-1]) {

                l.push_back(v[i]);

            }
        }
    }
    cout << mak << endl;
}
