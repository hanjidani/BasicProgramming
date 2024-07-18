#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;

int main(){
	double x, sum = 0, pow = 1;
	int n, fac = 1;
	cin>>n;
	cin>>x;
	for(int i = 0; i < n; i++){
		pow = 1;
		fac = 1;
		for(int j = 1; j <= i; j++){
			pow *= x;
			fac *= j;
		}
		sum += pow / double(fac);
	}
	cout<<setprecision(2)<<fixed<<sum<<endl;
	return 0;
}
