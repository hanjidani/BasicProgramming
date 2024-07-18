#include<iostream>
#include<cmath>
#include<iomanip>
#include<string.h>

// just a template to start

using namespace std;

void iscirc(double r, double x, double y){
	x = x * x;
	y = y * y;
	r = r * r;
	if((x + y) - r <= 0.001)	cout<<"Yes";
	else		cout<<"No";
}

void isellipse(double r1, double r2, double x, double y){
	r1 = r1 * r1;
	r2 = r2 * r2;
	x = (x * x) / r1;
	y = (y * y) / r2;
	if((x + y) - 1 <= 0.001)	cout<<"Yes";
	else		cout<<"No";
	
}

int main(){
	char type;
	double r1,r2,x,y;
	while(true){
		cin>>type;
		if(type == 'e')	return 0;
		else if(type == 'c'){
			cin>>r1>>x>>y;
			iscirc(r1, x, y);
		} else if(type == 'o'){
			cin>>r1>>r2>>x>>y;
			isellipse(r1, r2, x, y);
		}
	}	
	return 0;
}
