#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()

using namespace std;

int main() {
	int k,n;
	double minn = 100000000;
	vector<double> v;
	cin >> n >> k;
	for(int i=0;i<n;i++){
		double x,y,z;
		cin >> x >> y >> z;
		v.push_back(sqrt(x*x + y*y + z*z));
	}
	sort(v.begin(),v.end());
	cout << fixed << setprecision(10) << v[k-1];
	return 0;
}