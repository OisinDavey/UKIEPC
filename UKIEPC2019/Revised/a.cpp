#include <bits/stdc++.h>
#define f first
#define s second

using namespace std;

typedef pair<int, int> ii;

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

int s,c;
int si;
vector<ii > sv;
vector<ii > cv;

vector<ii > seg;

ii diff(ii a,ii b){
	if(a.f == 0 && a.s == 0){
		return b;
	}if(b.f == 0 && b.s == 0){
		return a;
	}else{
		return {max(a.f,b.f),min(a.s,b.s)};
	}
}

ii fill(int pos){
	if(pos >= si)
		return seg[pos];
	else
		return seg[pos] = diff(fill(pos*2),fill(pos*2+1));
}

int search(ii x,int pos){
	if(pos >= si){
		if(seg[pos].f >= x.f && seg[pos].s <= x.s){
			return pos-si;
		}else{
			return -1;
		}
	}else{
		if(seg[pos].f >= x.f && seg[pos].s <= x.s){
			int y = search(x,pos*2);
			if(y != -1){
				return y;
			}else{
				int w = search(x,pos*2+1);
				if(w != -1){
					return w;
				}else{
					return -1;
				}
			}
		}else{
			return -1;
		}
	}
}

int main(){
	int count = 0;
	cin >> s;
	for(int i=0;i<s;++i){
		ii x;
		cin >> x.f >> x.s;
		sv.push_back(x);
	}cin >> c;
	for(int i=0;i<c;++i){
		ii x;
		cin >> x.f >> x.s;
		cv.push_back(x);
	}
	si = binpow(2,ceil(log2((double)s)));
	seg.resize(si*2);
	for(int i=0;i<s;++i){
		seg[i+si]=sv[i];
	}fill(1);
	for(int i=0;i<c;++i){
		count+=(search(cv[i],1)+1);
	}cout << count;
}