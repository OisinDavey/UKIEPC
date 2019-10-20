#include <bits/stdc++.h>
#define sz(x) (int)(x).size()
#define f first
#define s second
#define pi 3.141592653589

using namespace std;

double dp[200][200];
int p;
int t;
vector<int> l;
vector<int> m;

pair<double,double> H(int pos){
	if(pos == -1){
		return {0,0};
	}
	double theta = (2 * pi/t)*pos;
	return {(cos(theta)),(sin(theta))};
}

double dist(pair<double,double> a,pair<double,double> b){
	return sqrt((a.f-b.f)*(a.f-b.f)+(a.s-b.s)*(a.s-b.s));
}

double op(int pos,int ll){
	if(pos>=0){
		if(ll == sz(l)){
			return 0;
		}
		if(dp[pos][ll] >0){
			return dp[pos][ll];
		}

		double minn=100000000.00;
		for(int i=0;i<sz(m);i++){
			if(l[ll]==m[i]){
				minn=min(minn,dist(H(pos),H(i)) + op(i,ll+1));
			}
		}

		if(minn == 100000000.0){
			dp[pos][ll]=0.0;
			return dp[pos][ll];
		}
		dp[pos][ll] = minn;
		return dp[pos][ll];
	}else{	
		if(ll == sz(l)){
			return 0;
		}

		double minn=100000000.00;
		for(int i=0;i<sz(m);i++){
			if(l[ll]==m[i]){
				minn=min(minn,dist(H(pos),H(i)) + op(i,ll+1));
			}
		}

		if(minn == 100000000.0){
			return 0;
		}
		return minn;
	}
	
}

int main(){
	for(int i=0;i<101;i++){
		for(int j=0;j<101;j++){
			dp[i][j] = 0.0;
		}
	}
	cin >> p;
	
	for(int i=0;i<p;i++){
		int x;
		cin >> x;
		l.push_back(x);
	}
	
	cin >> t;
	for(int i=0;i<t;i++){
		int x;
		cin >> x;
		m.push_back(x);
	}
	cout << fixed << setprecision(10) << op(-1,0);
}