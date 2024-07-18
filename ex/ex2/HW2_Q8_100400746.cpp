#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;

int main(){
	double x, sum2 = 0, sum = 0, fi = 0, n = 0;
	
	while(true) {
		cin>>x;
		if(x == -1)	break;
		sum2 += (x * x);
		sum += x;
		n++;
	}
	fi = (sum2 - (sum * sum) / n) / n;
	cout<<fixed<<setprecision(2)<<fi<<endl;
	return 0;
}
