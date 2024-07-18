#include<iostream>
#include<cmath>
#include<iomanip>
#include<string.h>

using namespace std;

int main(){
	int n;
	cin>>n;
	int first = n * n + (n - 1) * (n - 1);
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			cout<<first - 2 * n * j<<' ';
		}
		cout<<endl;
		first += 2;
	}
	return 0;
}
