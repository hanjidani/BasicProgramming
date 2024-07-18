#include<iostream>
#include<cmath>

using namespace std;

int main(){
	double a,b,c,temp,i;
	cin>>a>>b>>c;
	// sort them in a b c
	if(a > b) {
		if(a > c){
			i = 1;
		} else {
			i = 3;
		}
	} else {
		if(b > c){
			i = 2;
		} else {
			i = 3;
		}
	}
	if(i == 2) {
		temp = a;
		a = b;
		b = temp;
	} else if(i == 3) {
		temp = a;
		a = c;
		c = temp;
	}

	if(a * a == b * b + c * c)	cout<<"YES"<<endl;
	else cout<<"NO"<<endl;
	
	return 0;
}
