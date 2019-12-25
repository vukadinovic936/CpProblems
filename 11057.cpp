#include <bits/stdc++.h>
using namespace std;
int main() {
//freopen("output.txt","w",stdout);
    int n;
    while(cin >> n){
    vector<int> books;
    for(int i=0;i<n;i++){
        int temp;
        cin >> temp;
        books.push_back(temp);
    }
    sort(books.begin(),books.end());
    int money;
    cin >> money;
    int a=100000;
    int b=0;
    for(int j=0;j<books.size();j++){
        int i=books[j];
        vector<int> copy=books;
        copy.erase(copy.begin()+j);
        if(binary_search(copy.begin(),copy.end(),(money-i))){
            if(abs(i-(money-i))<abs(a-b)){
                a=i;
                b=money-i;
            }
        }
    }
    cout <<"Peter should buy books whose prices are " << a << " and " << b << ".\n" << endl;
    }
}
