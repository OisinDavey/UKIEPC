#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()

using namespace std;

int main() {
	int n;
	string s,t="";
	cin>>s;
	n=sz(s);
	if (n==1)
	{
		cout<<s[0];
	}
	else
	{
		if (s[1]-'0'<5)
		{
			cout<<s[0];
		}
		else
		{
			cout<<(s[0]-'0')+1;
		}
	}
	for (int i=1;i<n;++i)
	{
		cout<<0;
	}
	return 0;
}