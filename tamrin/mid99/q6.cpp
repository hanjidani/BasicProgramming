#include<iostream>
#include<cmath>
#include<iomanip>
#include<string.h>

// just a template to start

using namespace std;

int chartoint(char i){
	return i - '0';
}

int addsign(long long int x){
	int sum = 0;
	while(x > 0){
		sum += x % 10;
		x /= 10;
	}
	return sum;
}

int main(){
	int x = 1;
	string num;
	cin>>num;
	if(num.length() == 1){
		cout<<0;
		return 0;
	}
	long long int sum = 0;
	for(int i = 0; i < num.length(); i ++){
		sum += chartoint(num[i]);
	}
	while(sum >= 10){
		sum = addsign(sum);
		x++;
	}
	cout<<x;
	return 0;
}
