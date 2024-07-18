#include<iostream>
#include<cmath>
#include<iomanip>
#include<string.h>

using namespace std;

bool find(int a, int b){
	if(b == 0)	return true;
	if(a > 0 && b < 0)	return true;
	if(a < 0 && b > 0)	return true;
	return false;
}

int main(){
	int n;
	cin>>n;
	if(n == 0){
		cout<<0;
		return 0;
	}
	int prin, in;
	cin>>prin;
	if(n == 1){
		if(prin == 0){
			cout<<1;
			return 0;
		} else {
			cout<<0;
			return 0;
		}
	}
	n--;
	int c = 0;
	if(prin == 0)	c++;
	for(int i = 0; i < n; i++){
		cin>>in;
		if(find(prin, in))	c++;
		prin = in;
	}
	cout<<c;
	return 0;
}
