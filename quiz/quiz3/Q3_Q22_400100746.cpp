#include<iostream>
#include<cmath>
#include<iomanip>
#include<string.h>

// just a template to start

using namespace std;
void bidcons(long long int &sum, long long int &bid){
	if(sum - bid >= 0){
		sum = sum - bid;
	} else {
		bid = sum;
		sum = 0;
	}
}
int main(){
	long long int finit, sinit, tinit, fbid, sbid, tbid,n;
	cin>>finit>>sinit>>tinit>>n;
	if(n == 0)	return 0;
	for(int i = 0; i < n; i++){
		cin>>fbid>>sbid>>tbid;
	}
	bidcons(finit, fbid);
	bidcons(sinit, sbid);
	bidcons(tinit, tbid);
	if(fbid >= sbid){
		if(fbid >= tbid)	cout<<1<<endl<<finit;
		else			cout<<3<<endl<<tinit;
	} else {
		if(sbid >= tbid)	cout<<2<<endl<<sinit;
		else 			cout<<3<<endl<<tinit;
	}
	return 0;
}
