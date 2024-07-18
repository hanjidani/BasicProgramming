#include<iostream>
#include<cmath>
#include<iomanip>
#include<string.h>

// just a template to start

using namespace std;

int allSafe(int n){
	if(n == 0)	return 0;
	else if(n == 1)	return 1;
	else if(n >= 2 && n <= 4)
		return allSafe(n - 1) + allSafe(n - 2) + n * n;
	else if(n >= 5 && n <= 19)
		return allSafe(n - 1) + allSafe(n - 2) + 2 * n * n;
	else 
		return -1;
}

int main(){
	int n;
	cin>>n;
	n = allSafe(n);
	if(n != -1)
		cout<<n;
	else
		cout<<"che khabare";	
	return 0;
}
