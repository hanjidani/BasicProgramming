#include<iostream>
#include<cmath>
#include<iomanip>
#include<string.h>

// just a template to start

using namespace std;

int sum(int a){
	int sum = 0;
	while( a != 0){
		sum += a % 10;
		a /= 10;
	}
	return sum;
}

int prime(int x){
	int sum = 0;
	for(int i = 2; i <= x; i++){
		bool first = false;
		while(x % i == 0){
			if(!first){
				sum += i;
				first = true;
			}
		x /= i;
		}
	}
	return sum;

}

int d(int x){
	return x + prime(x) + sum(x);
}
int main(){
	int temp = 0, x,n;
	cin>>n;
	bool no = true;
	for(int i = 0; i < n; i++){
		cin>>x;
		no = true;
		for(int i = 2; i < x; i++){
			temp = d(i);
			//cout<<temp<<"\t"<<i<<endl;
			if(temp == x){
				no = false;
				cout<<"Yes"<<" "<<i<<endl;
				break;
			}
		}
		if(no)	cout<<"No"<<endl;
		temp = 0;
	}
	return 0;
}
