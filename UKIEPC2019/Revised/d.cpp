#include <bits/stdc++.h>

using namespace std;

int main(){
	vector<double> v;
	int n,k;
	cin >> n >> k;
	for(int i=0;i<n;i++){
		double x,y,z;
		cin >> x >> y >> z;
		v.push_back(x*x+y*y+z*z);
	}sort(v.begin(),v.end());
	cout << fixed << setprecision(10) << sqrt(v[k-1]);
}