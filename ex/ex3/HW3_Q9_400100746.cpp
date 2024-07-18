#include<iostream>
#include<cmath>
#include<iomanip>
#include<string.h>

// just a template to start

using namespace std;

int main(){
	long long int a, n, m, temp;
	
	cin>>a>>n>>m;
	a = a % m;
	temp = 1;
	// the stack algo
	while(n > 0){
		if(n % 2 == 1){
			temp = (a * temp) % m;
			n --;
		}
		a = (a * a) % m;
		n /= 2;
	}
	cout<<temp % m;
	return 0;
}
