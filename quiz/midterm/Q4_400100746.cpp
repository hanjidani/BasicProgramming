#include<iostream>
#include<cmath>
#include<iomanip>
#include<string.h>

// just a template to start

using namespace std;

int chartoint(char ch){
	return ch - '0';
}

int main(){
	char ch;
	int sum = 0, x = 0;
	bool flag = true, amal = true, first = true; //true for plus and false for minus
	while(flag){
		cin>>ch;
		if(ch == 'c'){
			flag = false;
		} else {
			if(ch == '+'){
				if(amal)	sum += x;
				else 		sum -= x;
				x = 0;
				amal = true;
			} else if(ch == '-'){
				if(amal)	sum += x;
				else 		sum -= x;
				x = 0;
				amal = false;
			} else{
				x = (10 * x) + chartoint(ch);
			}
		}
	}
	if(amal)	sum += x;
	else		sum -= x;
	cout<<sum;
	return 0;
}
