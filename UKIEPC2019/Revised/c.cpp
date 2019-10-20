#include <bits/stdc++.h>

using namespace std;

int main(){
	map<int,int > m;
	int h,c;
	cin >> c >> h;
	vector<int> v[c/h];
	for(int i=0;i<c;i++){
		int x;
		cin >> x;
		m[x]++;
	}
	for(int i=0;i<(c/h);++i){
		int co=0;
		for(auto it = m.begin();co<h;++it){
			if(it == m.end()){
				cout << "impossible";
				return 0;
			}
			if(it->second > 0){
				v[i].push_back(it->first);
				co++;
				it->second--;
			}
		}
	}for(int i=0;i<(c/h);i++){
		for(int j=0;j<v[i].size();j++){
			cout << v[i][j] << ' ';
		}cout << endl;
	}
}