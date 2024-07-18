#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;

int main(){
	double i, w,s,sw;
	while(true) {
		cin>>i;
		if(i == 0)	break;
		cin>>w;
		s += i * w;
		sw += w;
	}
	cout<<fixed<<setprecision(3)<<s / sw<<endl;
	return 0;
}
