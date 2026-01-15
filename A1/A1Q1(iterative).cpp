#include<bits/stdc++.h>
using namespace std;

int main() {
	vector<int> arr={-2,-3,-5};
	int finans=INT_MIN;
	for(int i=0; i<arr.size();i++) {
		int ans=0;
		for(int j=i; j<arr.size(); j++) {
			ans+=arr[j];
			if(ans>finans) finans=ans;
		}
	}
	cout<<finans;
}