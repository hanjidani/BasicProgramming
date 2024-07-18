#include<iostream>
#include<cmath>
#include<iomanip>
#include<string.h>

// just a template to start

using namespace std;

int max(int arr[], int size){
	int m = arr[0];
	for(int i = 1; i < size; i++)
		if(arr[i] > m)
			m = arr[i];
	return m;
}

int digitSum(int x){
	int ret = 0;
	while(x > 0){
		ret += x %10;
		x /= 10;
	}
	return ret;
}

void cal(char pm[], int arr[], int size){
	for(int i  = 0; i < size; i++){
		int x = pm[i];
		while(x > 9){
			x = digitSum(x);
		}
		arr[i] = x;
	}
}

void arrPrint(int arr[], int size){
	int n = max(arr, size);
	for(int i = 1; i <= n; i++){
		for(int j = 0; j < size; j++){
			if(arr[j] >= i){
				if(i % 2 == 0)	cout<<1;
				else 			cout<<0;
			} else {
				cout<<" ";
			}
		}
		cout<<endl;
	}
}

int main(){
	int n;
	cin>>n;
	char pm[n];
	cin>>pm;
	int arr[n];
	cal(pm, arr, n);
	arrPrint(arr, n);
	
	return 0;
}
