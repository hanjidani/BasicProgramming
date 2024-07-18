#include<iostream>
#include<cmath>
#include<iomanip>
#include<string.h>

// just a template to start

using namespace std;

// n is the number
// x is the base

int biggestpow(long long int x, long long int n){
	long long int lastpower = 1, t = 0;
	while(lastpower <= n){
			t++;
			lastpower *= x;
	}
	return t - 1;
}

// temp is the base
// n is the number

int biggestz(long long int tt, long long int n){
	return	(n - (n % tt)) / tt;
}

void refactor(long long int x){
	switch(x){
		case 0:
			cout<<'0';
			break;
		case 1:
			cout<<'1';
			break;
		case 2:
                        cout<<'2';
                        break;
                case 3:
                        cout<<'3';
                        break;
		case 4:
                        cout<<'4';
                        break;
		case 5:
                        cout<<'5';
                        break;	
		case 6:
                        cout<<'6';
                        break;
		case 7:
                        cout<<'7';
                        break;
		case 8:
                        cout<<'8';
                        break;
		case 9:
                        cout<<'9';
                        break;
		case 10:
                        cout<<'A';
                        break;
		case 11:
                        cout<<'B';
                        break;
		case 12:
                        cout<<'C';
                        break;
		case 13:
                        cout<<'D';
                        break;
		case 14:
                        cout<<'E';
                        break;
		case 15:
                        cout<<'F';
                        break;
	
	}
}

int main(){
	long long int n, x, t = 0, temp,ttemp;
	cin>>n>>x;
	t = biggestpow(x, n);
	 for(int i = t; i >= 0; i--){
		ttemp = pow(x, i);
		//cout<<ttemp<<n<<endl;
		temp = biggestz(ttemp, n);
		//cout<<ttemp<<temp<<endl;
		refactor(temp);
		n = n - (temp * ttemp);
	}
	return 0;
}
