#include<iostream>
#include<cmath>
#include<iomanip>
#include<string.h>

// just a template to start

using namespace std;

int main(){
	int n, space = 0, total = 0, temp = 0;
	cin>>n;
	total = 2 * n - 1;
	if(n == 1){
		cout<<'*';
		return 0;
	}
	for(int i = 1; i < n; i++){
		if(i == 1){
			temp = (total - 1) / 2;
			for(int j = 0; j < temp; j++)	cout<<' ';
			cout<<'*';
		} else {
			space = 2 * i - 3;
			temp = (total - space - 2) / 2;
			for(int j = 0; j < temp; j++)	cout<<' ';
			cout<<'*';
			for(int j = 0; j < space; j++)	cout<<' ';
			cout<<'*';
		}
		cout<<endl;
	}	
	if(n > 1){
		for(int i = 1; i < n;i++){
			cout<<'*'<<' ';
		}
		cout<<'*';	
	}
	return 0;
}
