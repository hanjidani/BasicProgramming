#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;

int ragham(int a){
	int c = 0;
	while(a > 0){
		c++;
		a /= 10;
	}
	return c;
}

bool special(int a, int i){
	bool flag = true;
	while(a > 0){
		if(a % 10 != i)	flag = false;
		a /= 10;
	}
	return flag;
}

int main(){
	long long int n,i;
	cin>>n>>i;
	int r = ragham(n);
	if(special(n, i)){
		cout<<"-1";
		return 0;
	}
	int k[r];
	for(int j = r - 1; j >= 0; j--){
		int t = n % 10;
		n /= 10;
		k[j] = t;
	}

	
	for(int j = 0; j < r; j++){
		if(k[j] != i)	cout<<k[j];
	}
	return 0;
}
