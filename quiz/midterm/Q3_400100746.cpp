#include<iostream>
#include<cmath>

// just a template to start

using namespace std;

int countM(long long int a){
	if(a == 1)	return 1;
	int t = 1;
	long long int x = sqrt(a);
	for(int i = 2; i <= x; i ++){
		if(a % i == 0){
			t++;
		}
	}
	
	if(double(x) == sqrt(a))	return (2 * t) - 1;
	else 						return 2 * t;
}

int main(){
	int k, c = 0, i = 1;
	cin>>k;
	long long int t = 0;
	//cout<<countM(3);
	while(c <= k){
		t = t + i;
		c = countM(t);
		i++;
		cout<<t<<"\t"<<c<<endl;
	}
	return 0;
}
