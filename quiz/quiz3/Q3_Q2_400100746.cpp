#include<iostream>
#include<cmath>
#include<iomanip>
#include<string.h>

// just a template to start

using namespace std;
void bidcons(double &sum, double bid, double &prbid){
	if(sum + (prbid - bid) >= 0){
		sum = sum + (prbid - bid);
		prbid = bid;
	} else {
		prbid = prbid + sum;
		sum = 0;
	}
}
int main(){
	double finit, sinit, tinit, fbid, sbid, tbid, fpr, spr, tpr,n;
	cin>>finit>>sinit>>tinit>>n;
	for(int i = 0; i < n; i++){
		cin>>fbid>>sbid>>tbid;
		bidcons(finit, fbid, fpr);
		bidcons(sinit, sbid, spr);
		bidcons(tinit, tbid, tpr);
	}
	if(fpr >= spr){
		if(fpr >= tpr)	cout<<1<<endl<<fixed<<setprecision(3)<<finit;
		else		cout<<3<<endl<<fixed<<setprecision(3)<<tinit;
	} else {
		if(spr >= tpr)	cout<<2<<endl<<fixed<<setprecision(3)<<sinit;
		else 		cout<<3<<endl<<fixed<<setprecision(3)<<tinit;
	}
	return 0;
}
