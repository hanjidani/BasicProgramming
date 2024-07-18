#include<iostream>
#include<cmath>
#include<iomanip>
#include<string.h>

// just a template to start

using namespace std;

double bast(double x, int n){
	double soorat = x, makhraj = 1, sum = 0;
	for(int i = 0; i < n; i ++){
		sum += (soorat) / (makhraj);
		soorat *= x * x;
		makhraj += 2;
	}
	return sum;
}

int main(){
	long long int a, n;
	double x;
	cin>>a>>n;
	x =(-1) * ((1 - double(a)) / (1 + double(a)));
	cout<<2 * bast(x, n);
	return 0;
}
