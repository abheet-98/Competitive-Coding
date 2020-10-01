#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	vector<int> a = {1, 2, 3, 4};
	int s=0;
	int l=1,r=a.size();
	for(int i=0;i<a.size();i++){
	    s+=a[i]*l*r;
	    l++;
	    r--;
	}
	cout<<s;
	return 0;
}
