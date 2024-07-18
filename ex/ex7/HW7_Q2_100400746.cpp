#include<iostream>
#include<cmath>
#include<iomanip>
#include<string.h>

// just a template to start

using namespace std;

void draw7(int x){
	if(x > 0){
		cout<<"\\";
		for(int i = 0; i < 2 * x; i++)
			cout<<"*";
		cout<<endl;
		for(int i = 2 * x - 1; i > 0; i--){
			for(int j = 1; j < i; j++)
				cout<<" ";
			cout<<"\\*"<<endl;
		}
		draw7(x - 1);
	}
}

int main(){
	int n;
	cin>>n;
	draw7(n);
	return 0;
}
