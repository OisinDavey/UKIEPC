#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()

using namespace std;

int main() {
	int n,c,ans=0;
	cin >> n >> c;

	int tmp;	
	vector<int> buckets;
	for(int i = 0; i < n; i++) {
		cin >> tmp;
		buckets.push_back(tmp);
	}
	sort(buckets.begin(),buckets.end());
	int a=0,b=n-1;
	while (b>=a)
	{
		if (buckets[a]+buckets[b]<=c)
		{
			++a;
		}
		--b;
		++ans;
	}
	cout<<ans;
	return 0;
}