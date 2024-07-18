#include<iostream>
#include<cmath>
#include<iomanip>
#include<string.h>

// just a template to start

using namespace std;

int ref(char i){
	return int(i) - int('0');
}

int main(){
	int n;
	long long int sum = 0;
	string input;
	cin>>n;
	for(int i = 0; i < n; i++){
		cin>>input;
		for(int j = 0; j < input.length(); j++){
			sum += ref(input[j]);	
		}
	}	
	cout<<sum;
	return 0;
}
