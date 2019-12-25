#include <bits/stdc++.h>
#define vi vector<int>
using namespace std;
int a;
int b;
int row[8];
int counter;
bool place(int r,int c){
	for(int i=0;i<c;i++){
		if(row[i]==r || abs(row[i]-r)==abs(i-c)){
			return false;
		}
	}
	return true;
}
void backtrack(int c){
	if(c==8 && row[b]==a){
		counter++;
		printf(" %d      %d",counter,row[0]+1);
		for(int i=1;i<8;i++){
			printf(" %d",row[i]+1);
		}
		printf("\n");
	}	
	for(int r=0;r<8;r++){
		if(place(r,c)){
			row[c]=r;
			backtrack(c+1);
		}
	}
}
int main(){
	int q;
	while(q--){
	counter=0;	
	cin >> q;
	cin >> a;
	cin >> b;
	a--;
	b--;
	printf("SOLN       COLUMN\n");
	printf(" #      1 2 3 4 5 6 7 8\n");
	printf("\n");
	memset(row,0,sizeof row);
	backtrack(0);
	}
}
