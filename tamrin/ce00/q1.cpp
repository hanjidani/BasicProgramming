#include<iostream>
#include<cmath>
#include<iomanip>
#include<string.h>

// just a template to start

using namespace std;

int main(){
	int n;
	cin>>n;
	for(int i = 0; i < n; i ++)	cout<<'*';
	cout<<endl;
	int is = (n - 3), os = 0;
	int temp = (n / 2) + 1;
	for(int i = 0; i < temp; i ++){
		cout<<'*';
		for(int j = 0; j < is; j++)	cout<<' ';
		cout<<'*';
		for(int j = 0; j < os; j++)     cout<<' ';
		cout<<'*'<<endl;
		is--;
		os++;
	}
	is++;
	os--;
	temp -= 1;
	for(int i = 0; i < temp; i ++){
                cout<<'*';
                for(int j = 0; j < is; j++)     cout<<' ';
                cout<<'*';
                for(int j = 0; j < os; j++)     cout<<' ';
                cout<<'*'<<endl;
                is++;
                os--;
        }
	for(int i = 0; i < n; i ++)     cout<<'*';
	return 0;
}
