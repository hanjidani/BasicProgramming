#include<iostream>
#include<cmath>
#include<iomanip>
#include<string.h>

// just a template to start

using namespace std;

long int sade(int x, int n){
	while(x % n == 0){
		x /= n;
	}
	return x;
}

int main(){
	long int x, j;
	bool t = false;
	cin>>x;
	j = sqrt(x);
	for(int i = 2; i <= j; i ++){
		if(x % i == 0){
			if(t)	cout<<" ";
			t = true;
			cout<<i;
			x = sade(x, i);
		}
	}
	return 0;
}
