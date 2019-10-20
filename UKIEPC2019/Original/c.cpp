#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()

using namespace std;

int main() {
	int n,h;
	cin >> n >> h;
	int tmp;
	map<int,int> occurs;
	vector<int> pileK;
	int keys = 0;
	for(int i = 0; i < n; i++) {
		cin >> tmp;
		++occurs[tmp];
		if(occurs[tmp] == 1) {
			++keys;
			pileK.push_back(tmp);
		}
	}
	vector<pair<int,int>> vP;
	for (int i=0;i<keys;++i)
	{
		vP.push_back(make_pair(occurs[pileK[i]],pileK[i]));
	}
	sort(vP.begin(),vP.end());
	if (keys<h)
	{
		cout<<"impossible";
		return 0;
	}
	while(keys>=h) {
		int cardsPicked = 0;
		int i = sz(vP)-1;
		while(cardsPicked < h) {
			// cout << i << ":" << endl;
			if(vP[i].first > 0) {
				--vP[i].first;
				++cardsPicked;
				cout << vP[i].second << " ";
			}
			if(vP[i].first == 0){
				--keys;
				vP[i].first = -1;
			}
			--i;
		}
		cout << endl;
	}

	// for(int i = 0; i < keys; i++) {
	// 	cout << vP[i].first << "," << vP[i].second << endl;
	// }

	return 0;
}