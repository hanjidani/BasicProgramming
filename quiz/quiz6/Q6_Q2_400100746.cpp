#include<iostream>
#include<cmath>
#include<iomanip>
#include<string.h>

// just a template to start

using namespace std;

int count(string str, int len){
	int c = 0;
	for(int i = 0; i < len; i++){
		if(str[i] == 'I')	c++;
	}
	return c;
}
long long int factorial(int st, int end){
	long long int ret = 1;
	for(int i = st; i <= end; i++){
		ret *= i;
	}
	return ret;
}
int main(){
	int n, len, I;
	cin>>n;
	string s;
	cin>>s;
	len = s.length();
	if(len == 2 * n){
		cout<<0;
		return 0;
	}
	I = count(s, len);
	if(2 * I != len){
		
	}
	int t = n - I;
	int p = 2 * I - len;
	if(t != 0)	cout<<(factorial((max(t, p)) + 1, n - len + I)) / (factorial(1,min(t, p)));
	else 		cout<<1;
	return 0;
}
