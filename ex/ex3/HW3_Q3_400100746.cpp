#include<iostream>
#include<cmath>
#include<iomanip>
#include<string.h>

// just a template to start

using namespace std;

void fib(int n){
	int a = 1,b = 1,temp;
	while(b < n){
		temp = b;
		b = a + b;
		a = temp;
	}
	if(n == b)	cout<<'f';
}

void sqr(int n){
	float a = sqrt(n);
	if(a - int(a) == 0)	cout<<'s';
}

void prime(int n){
	if(n == 1)	return;
	int t = 2;
	float sq = n / 2;
	for(int i = 2; i <= sq; i++){
		if(n % i == 0)	t++;
	}
	if(t == 2)	cout<<'p';
	else if(t >= 15)	cout<<'d';
}
int main(){
	int n;
	cin>>n;
	fib(n);
	sqr(n);
	prime(n);
	cout<<'.';
	return 0;
}
