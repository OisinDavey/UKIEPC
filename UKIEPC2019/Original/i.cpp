#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()

using namespace std;

ll binpow(ll a, ll b) {
	if (b==0) {
		return 1;
	}
	ll res = binpow(a,b/2);
	if(b%2)
		return res * res * a;
	return res * res;
}

vector<int> nextLine(vector<int> v)
{
	vector<int> m;
	int n=sz(v);
	for (int i=1;i<n;++i)
	{
		m.push_back(v[i-1]+v[i]);
	}
}

int main(){
	int n,k,x,diff;
	cin >> n >> x;
	int top = binpow(2, n-1);
	if(x < top) {
		cout << "impossible";
		return 0;
	}
	diff=x-top;
	for(int i = n-1; i > 0; --i) {
		int val = binpow(2, i);
		cout<< binpow(2,i-1) * 2 + diff <<" ";
		for (int j=0;j<(n-i)-1;++j)
		{
			cout<<val<<" ";
		}
		cout<<endl;
	}
	cout << 1 + diff << " ";
	for(int i = 0; i < n-1; i++) {
		cout << 1 << " ";
	}
	cout << endl;
	return 0;
}