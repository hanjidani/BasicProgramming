#include<iostream>
#include<cmath>
#include<iomanip>
#include<string.h>

// just a template to start

using namespace std;

long long int bmm(long long int a, long long int b){
	long long int temp = 0;
	if(a < b){
		temp = a;
		a = b;
		b = temp;
	}
	while(b != 0){
		temp = a;
		a = b;
		b = temp % b;
	}
	return a;
}

long long int kmm(long long int a, long long int b){
	return (a*b) / bmm(a, b);
}

int main(){
	int n;
	cin>>n;
	long long int t = 1;
	for(int i = 2; i <=n; i ++){
		t = kmm(t, i);
	}
	cout<<t;
	return 0;
}
