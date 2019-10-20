#include<bits/stdc++.h>
#define f first
#define s second
using namespace std;

int main(){
	int n,c;
	cin >> c >> n;
	int T = 0;
	int hatp;
	int dist[c];
	pair<int,int> coef[c];
	for(int i=0;i<c;++i){
		dist[i] = i+1;
		coef[i].s=i+1;
		coef[i].f=0;
	}
	cin >> hatp;
	for(int i=1;i<n;++i){
		int pos;
		cin >> pos;
		++coef[dist[pos-1]-1].f;
		swap(dist[hatp-1],dist[pos-1]);
		hatp=pos;
	}sort(coef,coef+c,greater<pair<int,int>>());
	for(int i=0;i<c-1;++i){
		cout << coef[i].s << ' ';
	}
}