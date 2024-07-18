#include<iostream>
#include<cmath>
#include<iomanip>
#include<string.h>

// just a template to start

using namespace std;
char upper(char ch){
	if(ch > 'Z'){
		return char(ch - 32);
	} else {
		return ch;
	}
}
int main(){
	//cout<<lower('x');
	double n, x,sum = 0;
	char ch = 'A';
	cin>>n>>sum;
	for(int i = 0; i < n; i++){
		cin>>ch>>x;
		if(upper(ch) == 'S')	sum += x;
		else if(upper(ch) == 'B')	sum -= x;
	}
	if(ch != 'A'){
		if(sum - int(sum) > 0)	cout<<fixed<<setprecision(3)<<sum;
		else cout<<int(sum);
	}
	return 0;
}
