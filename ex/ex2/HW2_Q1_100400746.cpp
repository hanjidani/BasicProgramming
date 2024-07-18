#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;
// find the greatest power of 2
int FGP2(long long int a){
	int i = 0;
	while(pow(2,i) < a)	i++;
	if(a == pow(2,i))	return i;
	else			return i - 1;
}

int main(){
	long long int n,a;
	cin>>n;

	if(n >= 0)	cout<<"0";
	else{
		cout<<"1";
		n = (-1) * n;
	}
	
	a = FGP2(n);
	for(int i = 0; i < 30 - a; i++)	cout<<"0";

	while(a >= 0){
		if((n - pow(2, a)) >= 0){
			cout<<"1";
			n -= pow(2,a);
		} else {
			cout<<"0";
		}
		a -= 1;
	}

	return 0;
}
