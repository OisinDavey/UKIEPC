#include <bits/stdc++.h>

using namespace std;

int main(){
	string s;
	cin >> s;
	if(s.size()==1){
		cout << s;
		return 0;
	}else{
		if(s[1] < '5'){
			cout << s[0];
			for(int i=1;i<s.size();i++)
				cout << '0';
		}else{
			cout << (char)(s[0]+1);
			for(int i=1;i<s.size();i++)
				cout << '0';
		}
	}
}