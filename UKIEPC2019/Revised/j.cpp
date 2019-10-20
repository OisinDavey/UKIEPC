#include <bits/stdc++.h>
#define pi 3.14159265358979323846
#define f first
#define s second

using namespace std;

int L;
int M;
vector<int> l;
vector<int> m;
double dp[101][101];

double dist(pair<double,double> a,pair<double,double> b){
	return sqrt(((a.f-b.f)*(a.f-b.f))+((a.s-b.s)*(a.s-b.s)));
}

pair<double,double> pos2coord(int pos){
	return {cos(pos*2*pi/M),sin(pos*2*pi/M)};
}

double Op(int Mpos,int Lpos){
	double minn = 10000000000;
	if(Mpos == -1){
		for(int i=0;i<M;++i)
			if(m[i] == l[Lpos])
				minn = min(minn,Op(i,Lpos+1)+dist({0,0},pos2coord(i)));
		return minn;
	}else{
		if(Lpos == L)
			return 0;
		if(dp[Mpos][Lpos] != 0)
			return dp[Mpos][Lpos];
		for(int i=0;i<M;++i)
			if(m[i] == l[Lpos])
				minn = min(minn,Op(i,Lpos+1)+dist(pos2coord(Mpos),pos2coord(i)));
		return dp[Mpos][Lpos]=minn;
	}
}

int main(){
	int x;
	cin >> L;
	for(int i=0;i<L;++i){
		cin >> x;
		l.push_back(x);
	}cin >> M;
	for(int i=0;i<M;++i){
		cin >> x;
		m.push_back(x);
	}cout << fixed << setprecision(10) << Op(-1,0);
}