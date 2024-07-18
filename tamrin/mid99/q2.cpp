#include<iostream>
#include<cmath>
#include<iomanip>
#include<string.h>

// just a template to start

using namespace std;

int main(){
	int m,n,k, temp;
	cin>>m>>n>>k;
	m = m % k;
	temp = 1;
	if(n == 1){
		cout<<m;
		return 0;
	}
	while(n > 1){
		if(n % 2 == 1){
			n = n -1;
			temp *= m;
		}
		temp *= m * m;
		temp %= k;
		n /= 2;
	}
	cout<<temp;
	return 0;
}
