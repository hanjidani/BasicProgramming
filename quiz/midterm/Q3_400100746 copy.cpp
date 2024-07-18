#include<iostream>
#include<cmath>

// just a template to start

using namespace std;

int countM(long long int a){
	if(a == 1)	return 1;
	int t = 1, c = 0;
	long long int x = (a / 2) + 1;
	for(int i = 2; i <= x; i ++){
		if(a % i == 0){
			c = 0;
			while(a % i == 0){
				a /= i;
				c++;
			}
			t *= (c+1);
		}
	}
	
	if(t == 1)	t = 2;
	return t;
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
	}
	cout<<t;
	return 0;
}