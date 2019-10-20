#include <bits/stdc++.h>

using namespace std;

int main(){
	int n,c;
	cin >> n >> c;
	int v[n],p1=0,p2=n-1;
	for(int i=0;i<n;i++)
		cin >> v[i];
	sort(v,v+n);
	while(p2>=p1){
		if((v[p1]+v[p2])<=c)
			++p1;
		--p2;
	}cout << n-p1;
}