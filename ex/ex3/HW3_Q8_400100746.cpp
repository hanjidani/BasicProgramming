#include<iostream>
#include<cmath>
#include<iomanip>
#include<string.h>

// just a template to start

using namespace std;

int main(){
	int n, first = -1, pr = -1, change = 0, x, zeros = 0, ones = 0;
	cin>>n;
	for(int i = 0; i < n; i++){
		cin>>x;
		if(first == -1){
			first = x;
			change ++;
		} else {
			if(pr != x)	change ++;	
		}
		if(x == 1)	ones ++;
		else if(x == 0)	zeros ++;
		pr = x;
	}
	//cout<<change<<endl;
	if(zeros != 0 && ones == 0)		cout<<1;
	else if(ones != 0 && zeros == 0)	cout<<0;
	else if(zeros == 1 && ones != 0)	cout<<1;
	else if(change == 3 && first == 1)	cout<<1;
	else if(change == 2)			cout<<1;
	else 					cout<<2;	
	return 0;
}
