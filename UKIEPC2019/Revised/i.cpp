#include <bits/stdc++.h>

using namespace std;

int binpow (int a, int n) {
	if (n == 0)
		return 1;
	if (n % 2 == 1)
		return binpow (a, n-1) * a;
	else {
		int b = binpow (a, n/2);
		return b * b;
	}
}

int main(){
	int n,x;
	cin >> n >> x;
	if(x >= binpow(2,n-1)){
		int a[n][n];
		memset(a,0,sizeof(a));
		a[0][0]=1+(x-binpow(2,n-1));
		for(int i=1;i<n;i++){
			a[0][i] = 1;
		}for(int i=1;i<n;i++){
			for(int j=0;j<(n-i);j++){
				a[i][j] = a[i-1][j] + a[i-1][j+1];
			}
		}for(int i=n-1;i>=0;i--){
			for(int j=0;j<(n-i);j++){
				cout << a[i][j] << ' ';
			}cout << endl;
		}
	}else{
		cout << "impossible";
	}
}