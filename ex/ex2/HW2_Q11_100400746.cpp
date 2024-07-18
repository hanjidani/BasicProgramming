#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;
bool bet(int a,int b,int c){
	int temp;
	if(a < b){
		temp = a;
		a = b;
		b = temp;
	}
	if(a > c && b < c)	return true;
	else return false;
}
int main(){
	int xa, ya, xb, yb, xf, yf;
	cin>>xa>>ya>>xb>>yb>>xf>>yf;
	if((xa == xb) && (xa == xf)){
		if(bet(ya, yb, yf)){
			cout<<(abs(ya - yb) + 2);
			return 0;
		}
	}
        else if((ya == yb) && (ya == yf)){
	       if(bet(xa, xb, xf)){
	       	       cout<<(abs(xa - xb) + 2);
		       return 0;
	       }
	}
	cout<<(abs(ya - yb) + abs(xa - xb));
	return 0;
}
